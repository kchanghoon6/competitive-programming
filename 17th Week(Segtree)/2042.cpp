#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M, K;
ll A[2000000];
ll tree[8000000];

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
   scanf("%lld %lld %lld", &N, &M, &K);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &A[i]);
      update_(1, 1, N, i, A[i]);
   }
   for(ll i=1; i<=M+K; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      if(a == 1)  update_(1, 1, N, b, c);
      else  printf("%lld\n", sum_(1, 1, N, b, c));
   }

   return 0;
}
