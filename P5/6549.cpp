#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N;
ll A[200000];
pll tree[800000];
ll maxi;

pll update_(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)   return tree[idx];
   if(sidx == eidx)  return tree[idx] = {val, t};
   ll midx = (sidx + eidx)/2;
   return tree[idx] = min(update_(2*idx, sidx, midx, t, val), update_(2*idx+1, midx+1, eidx, t, val));
}
pll min_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return {1e15, -1};
   if(s <= sidx && e >= eidx) return tree[idx];
   ll midx = (sidx + eidx)/2;
   return min(min_(2*idx, sidx, midx, s, e), min_(2*idx+1, midx+1, eidx, s, e));
}

ll f(ll l, ll r){
   if(l > r)  return 0;
   pll k = min_(1, 1, N, l, r);
   ll m = k.ss;
   maxi = max(maxi, (r-l+1)*k.ff);
   f(l, m-1);
   f(m+1, r);
   return 0;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   while(1){
      cin >> N;
      if(N == 0)  break;
      for(ll i=1; i<=N; i++){
         cin >> A[i];
         update_(1, 1, N, i, A[i]);
      }
      f(1, N);
      cout << maxi << "\n";
      for(ll i=1; i<=N; i++){
         A[i] = 0;
      }
      for(ll i=1; i<=4*N; i++){
         tree[i] = {0, 0};
      }
      maxi = 0;
      N = 0;
   }



   return 0;
}
