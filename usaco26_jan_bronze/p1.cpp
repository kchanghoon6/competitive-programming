#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll t;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> t;
   while(t--){
      ll a, b, ca, cb, fa;
      cin >> a >> b >> ca >> cb >> fa;
      fa -= a;
      fa -= (b/cb)*ca;
      if(fa <= 0){
         cout << 0 << "\n";
         continue;
      }
      ll r = b%cb;
      ll x = 0;
      if(ca > cb){
         x = fa;
         if(cb-r-1 > 0) x += cb-r-1;
      }
      else{
         ll k = (fa+ca-1)/ca;
         ll x1 = cb*k-r;
         ll x2 = fa+k*(cb-ca)+ca-1-r;
         x = max(x1, x2);
      }
      cout << x << "\n";
   }
   return 0;
}
