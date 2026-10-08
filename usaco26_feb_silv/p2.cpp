#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, q;
ll A[200005], F[200005];
ll T[800025];

ll mul(ll a, ll b){
   if(a > (ll)2e18/b)   return (ll)2e18;
   return a*b;
}

void build(ll nd, ll s, ll e){
   if(s == e){
      T[nd] = F[s];
      return;
   }
   ll m = (s+e)/2;
   build(2*nd, s, m);
   build(2*nd+1, m+1, e);
   T[nd] = mul(T[2*nd], T[2*nd+1]);
}

void upd(ll nd, ll s, ll e, ll i){
   if(s == e){
      T[nd] = F[i];
      return;
   }
   ll m = (s+e)/2;
   if(i <= m)   upd(2*nd, s, m, i);
   else   upd(2*nd+1, m+1, e, i);
   T[nd] = mul(T[2*nd], T[2*nd+1]);
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> n;
   for(ll i=1; i<=n; i++) cin >> A[i];
   F[1] = A[1]+1;
   for(ll i=2; i<=n; i++) F[i] = (A[i]+A[i-1]-1)/A[i-1];
   build(1, 1, n);
   cin >> q;
   while(q--){
      ll p, v, t;
      cin >> p >> v >> t;
      A[p] = v;
      if(p == 1)   F[1] = A[1]+1;
      else   F[p] = (A[p]+A[p-1]-1)/A[p-1];
      upd(1, 1, n, p);
      if(p < n){
         F[p+1] = (A[p+1]+A[p]-1)/A[p];
         upd(1, 1, n, p+1);
      }
      ll pn = T[1];
      ll ans = 0;
      if(t >= n)   ans = A[n]*((t-n+1)/pn);
      cout << ans << "\n";
   }
   return 0;
}
