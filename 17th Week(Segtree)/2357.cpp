#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;
ll A[200000];
ll tree[800000];
ll tree2[800000];

ll update_max(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)   return tree[idx];
   if(sidx == eidx)  return tree[idx] = val;
   ll midx = (sidx + eidx)/2;
   return tree[idx] = max(update_max(2*idx, sidx, midx, t, val), update_max(2*idx+1, midx+1, eidx, t, val));
}
ll update_min(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)   return tree2[idx];
   if(sidx == eidx)  return tree2[idx] = val;
   ll midx = (sidx + eidx)/2;
   return tree2[idx] = min(update_min(2*idx, sidx, midx, t, val), update_min(2*idx+1, midx+1, eidx, t, val));
}

ll max_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return 0;
   if(s <= sidx && e >= eidx) return tree[idx];
   ll midx = (sidx + eidx)/2;
   return max(max_(2*idx, sidx, midx, s, e), max_(2*idx+1, midx+1, eidx, s, e));
}

ll min_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return 1e10;
   if(s <= sidx && e >= eidx) return tree2[idx];
   ll midx = (sidx + eidx)/2;
   return min(min_(2*idx, sidx, midx, s, e), min_(2*idx+1, midx+1, eidx, s, e));
}

int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=4*N; i++){
      tree2[i] = 1e10;
   }
   for(ll i=1; i<=N; i++){
      scanf("%lld", &A[i]);
      update_min(1, 1, N, i, A[i]);
      update_max(1, 1, N, i, A[i]);
   }
   for(ll i=1; i<=M; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      printf("%lld %lld\n", min_(1, 1, N, a, b), max_(1, 1, N, a, b));
   }

   return 0;
}
