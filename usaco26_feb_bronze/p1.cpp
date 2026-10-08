#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;

ll n, k;
pll B[1000001];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   ll t;
   cin >> t;
   while(t--){
      cin >> n >> k;
      ll ak = abs(k);
      ll sg = (k > 0) ? 1 : -1;

      for(ll i=1; i<=n; i++){
         ll a;
         cin >> a;
         ll r = a % ak;
         if(r < 0) r += ak;
         ll q = (a - r) / ak;
         B[i] = {r, sg * q};
      }

      sort(B+1, B+n+1);

      ll ans = 0;
      ll prv = B[1].ss;
      for(ll i=2; i<=n; i++){
         if(B[i].ff != B[i-1].ff)
            prv = B[i].ss;
         else{
            ll cur = max(B[i].ss, prv + 1);
            ans += cur - B[i].ss;
            prv = cur;
         }
      }

      cout << ans << '\n';
   }
   return 0;
}
