#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll X[500005], Y[500005];

pll go(ll* A, ll n){
   sort(A+1, A+n+1);
   vector<pll> vc;
   ll i = 1;
   while(i <= n){
      ll v = A[i], cnt = 0;
      while(i <= n && A[i] == v) i++, cnt++;
      vc.push_back({v, cnt});
   }
   ll sn = 0, sx = 0, sz = vc.size();
   ll j = 0;
   while(j < sz){
      ll k = j;
      while(k+1 < sz && vc[k+1].ff == vc[k].ff+1) k++;
      ll tot = 0;
      for(ll m=j; m<=k; m++) tot += vc[m].ss;
      if(tot%2) return {-1, -1};
      ll carry = 0, s = 0;
      for(ll m=j; m<=k; m++){
         ll av = vc[m].ss-carry;
         if(m == k){
            s += av/2;
         }
         else{
            ll mx = min(av, vc[m+1].ss);
            if(mx%2 != av%2)   mx--;
            s += (av-mx)/2;
            carry = mx;
         }
      }
      sn += s;
      carry = 0; s = 0;
      for(ll m=j; m<=k; m++){
         ll av = vc[m].ss-carry;
         if(m == k){
            s += av/2;
         }
         else{
            ll co = av%2;
            s += (av-co)/2;
            carry = co;
         }
      }
      sx += s;
      j = k+1;
   }
   return {sn, sx};
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin >> t;
   while(t--){
      ll n;
      cin >> n;
      for(ll i=1; i<=n; i++) cin >> X[i] >> Y[i];
      pll rx = go(X, n), ry = go(Y, n);
      if(rx.ff < 0 || ry.ff < 0){
         cout << "NO\n";
         continue;
      }
      ll h = n/2;
      ll lo = rx.ff+ry.ff, hi = rx.ss+ry.ss;
      if(lo <= h && h <= hi && h%2 == lo%2)   cout << "YES\n";
      else   cout << "NO\n";
   }
   return 0;
}
