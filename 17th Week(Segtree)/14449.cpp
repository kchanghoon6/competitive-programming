#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N;
pll H[200000];
ll tree[800000];
ll P[200000];
ll L[200000];
ll R[200000];

ll update_(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)  return tree[idx];
   if(sidx == eidx)  return tree[idx] += val;
   ll midx = (sidx+eidx)/2;
   tree[idx] = update_(2*idx, sidx, midx, t, val) + update_(2*idx+1, midx+1, eidx, t, val);
   return tree[idx];
}
ll sum_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return 0;
   if(s <= sidx && e >= eidx) return tree[idx];
   ll midx = (sidx + eidx)/2;
   return sum_(2*idx, sidx, midx, s, e) + sum_(2*idx+1, midx+1, eidx, s, e);
}
int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      ll a;
      scanf("%lld", &a);
      H[i].ff = a;
      H[i].ss = i;
   }
   sort(H+1, H+N+1);
   for(ll i=1; i<=N; i++){
      P[H[i].ss] = i;   // 원래 숫자가 몇 번째 배치였는지를 알려줌
   }
   for(ll i=1; i<=N; i++){
      L[i] = sum_(1, 1, N, P[i]+1, N);
      update_(1, 1, N, P[i], 1);
   }
   for(ll i=1; i<=700000; i++){
      tree[i] = 0;
   }
   for(ll i=N; i>=1; i--){
      R[i] = sum_(1, 1, N, P[i]+1, N);
      update_(1, 1, N, P[i], 1);
   }
   ll cnt = 0;
   for(ll i=1; i<=N; i++){
      ll M = max(L[i], R[i]);
      ll m = min(L[i], R[i]);
      if(M > 2*m) cnt++;
   }
   printf("%lld\n", cnt);
   return 0;
}
