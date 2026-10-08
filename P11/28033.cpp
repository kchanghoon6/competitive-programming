#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll B[7];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   string str;
   cin >> str;
   ll n = str.size();
   ll r = n;
   ll ans = 0;
   string t = "bessie";

   for(ll i=0; i<n; i++){
      char c = str[i];
      B[0]++;
      for(ll j=5; j>=0; j--){
         if(c != t[j])  continue;
         B[j+1] += B[j];
         B[j] = 0;
      }
      ans += B[6]*r;
      B[0] += B[6];
      B[6] = 0;
      r--;
   }
   cout << ans << "\n";
   return 0;
}
