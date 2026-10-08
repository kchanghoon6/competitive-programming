#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

map<ll, ll> A;
ll D[200000];
ll n, t;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);


   cin >> n >> t;
   A[0] = 0;
   for(ll i=1; i<=n; i++){
      ll d, b;
      cin >> d >> b;
      A[d] = b;
      D[i] = d;
   }
   D[n+1] = t+1;
   ll s = 0;
   ll ans = 0;
   for(ll i=1; i<=n; i++){
      ll d = D[i];
      s += A[d];
      ll k = min(s, (D[i+1]-d));
      ans += k;
      s -= k;
   }
   cout << ans << "\n";


   return 0;
}
