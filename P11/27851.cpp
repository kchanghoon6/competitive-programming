#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n, k;
ll D[200000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n >> k;
   for(ll i=1; i<=n; i++)   cin >> D[i];
   ll ans = 1+k;
   for(ll i=1; i<=n-1; i++){
      if(D[i+1]-D[i] <= k){
         ans += D[i+1]-D[i];
      }
      else{
         ans += 1+k;
      }
   }
   cout << ans << "\n";



   return 0;
}
