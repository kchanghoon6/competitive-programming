#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll N, K;
pll A[200000];
ll tree[800000];
ll B[200000];
ll P[200000];

ll update_(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)   return tree[idx];
   if(sidx == eidx)  return tree[idx] += val;
   ll midx = (sidx+eidx)/2;
   return tree[idx] = update_(2*idx, sidx, midx, t, val) + update_(2*idx+1, midx+1, eidx, t, val);
}

ll sum_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return 0;
   if(s <= sidx && e >= eidx) return tree[idx];
   ll midx = (sidx+eidx)/2;
   return sum_(2*idx, sidx, midx, s, e)+sum_(2*idx+1, midx+1, eidx, s, e);
}


int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;
   for(ll i=1; i<=N; i++){
      cin >> A[i].ff;
      A[i].ss = i;
   }
   sort(A+1, A+N+1);
   for(ll i=1; i<=N; i++){
      P[A[i].ss] = i;
   }
   ll maxi = 0;
   for(ll i=N; i>=1; i--){
      maxi = max(maxi, sum_(1, 1, N, 1, P[i]-1));
      B[i] = maxi;
      update_(1, 1, N, P[i], 1);
   }
   for(ll i=1; i<=N; i++){
      if(B[i] == 0)  break;
      K++;
   }
   cout << K << "\n";
   for(ll i=1; i<=K; i++){
      cout << B[i] << " ";
   }
   cout << "\n";


   return 0;
}
