#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   ll ans = N;
   for(ll i=2; i*i<=N; i++){
      if(N%i != 0)   continue;
      ans = ans/i*(i-1);
      while(N%i == 0){
         N /= i;
      }
   }
   if(N > 1) ans = ans/N*(N-1);
   cout << ans << "\n";
   return 0;
}
