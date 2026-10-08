#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200000];
ll tree1[800000];
ll tree2[800000];
ll N, K, T;

ll update_min(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)   return tree1[idx];
   if(sidx == eidx)  return tree1[idx] = val;
   ll midx = (sidx+eidx)/2;
   return tree1[idx] = min(update_min(2*idx, sidx, midx, t, val), update_min(2*idx+1, midx+1, eidx, t, val));
}
ll update_max(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)   return tree2[idx];
   if(sidx == eidx)  return tree2[idx] = val;
   ll midx = (sidx+eidx)/2;
   return tree2[idx] = max(update_max(2*idx, sidx, midx, t, val), update_max(2*idx+1, midx+1, eidx, t, val));
}

ll min_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return 1e10;
   if(s <= sidx && e >= eidx) return tree1[idx];
   ll midx = (sidx+eidx)/2;
   return min(min_(2*idx, sidx, midx, s, e), min_(2*idx+1, midx+1, eidx, s, e));
}
ll max_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return -1e10;
   if(s <= sidx && e >= eidx) return tree2[idx];
   ll midx = (sidx+eidx)/2;
   return max(max_(2*idx, sidx, midx, s, e), max_(2*idx+1, midx+1, eidx, s, e));
}

int main(){
   scanf("%lld", &T);
   while(T--){
      scanf("%lld %lld", &N, &K);
      for(ll i=0; i<N; i++){
         A[i] = i;
         update_min(1, 0, N-1, i, i);
         update_max(1, 0, N-1, i, i);
      }
      for(ll i=1; i<=K; i++){
         ll q, a, b;
         scanf("%lld %lld %lld", &q, &a, &b);
         if(q==0){
            swap(A[a], A[b]);
            update_min(1, 0, N-1, a, A[a]);
            update_min(1, 0, N-1, b, A[b]);
            update_max(1, 0, N-1, a, A[a]);
            update_max(1, 0, N-1, b, A[b]);
            continue;
         }
         ll mini = min_(1, 0, N-1, a, b);
         ll maxi = max_(1, 0, N-1, a, b);
         if(mini == a && maxi == b) printf("YES\n");
         else printf("NO\n");
      }
   }

   return 0;
}
