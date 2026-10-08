#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll A[100000];
ll B[100000];
ll tree[500000];

ll update_(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)   return tree[idx];
   if(sidx == eidx)  return tree[idx] = val;
   ll midx = (sidx + eidx)/2;
   return tree[idx] = update_(2*idx, sidx, midx, t, val) + update_(2*idx+1, midx+1, eidx, t, val);
}

ll sum_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return 0;
   if(s <= sidx && e >= eidx) return tree[idx];
   ll midx = (sidx + eidx)/2;
   return sum_(2*idx, sidx, midx, s, e) + sum_(2*idx+1, midx+1, eidx, s, e);
}

int main(){
   ll result = 0;
   scanf("%lld", &N);
   for(ll i=1; i<=2*N; i++){
      scanf("%lld", &A[i]);
      if(B[A[i]]){
         result += sum_(1, 1, 2*N, B[A[i]]+1, i-1);
         update_(1, 1, 2*N, B[A[i]], 0);
         continue;
      }
      update_(1, 1, 2*N, i, 1);
      B[A[i]] = i;
   }
   printf("%lld\n", result);
   return 0;
}
