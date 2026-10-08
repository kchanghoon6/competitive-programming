#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n;
ll P[200000];
ll T[200000];
ll D[200000];
ll E[200000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   for(ll i=1; i<=n; i++)   cin >> P[i];
   for(ll i=1; i<=n; i++)   cin >> T[i];
   for(ll i=1; i<=n; i++)   D[i] = P[i]-T[i];

   for(ll i=1; i<=n+1; i++){
      E[i] = D[i]-D[i-1];
   }
   ll ans = 0;
   for(ll i=1; i<=n+1; i++){
      if(E[i] > 0)   ans += E[i];
   }
   cout << ans << "\n";

   return 0;
}
