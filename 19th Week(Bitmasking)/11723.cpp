#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll M;
ll S;
int main(){
   // freopen("in.txt", "r", stdin);
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> M;
   for(ll i=1; i<=M; i++){
      string str;
      ll x;
      cin >> str;
      if(str != "all" && str != "empty"){
         cin >> x;
      }
      if(str == "add"){
         if(!(S & (1LL<<x))){
            S += (1LL << x);
         }
      }
      if(str == "remove"){
         if(S & (1LL << x)){
            S -= (1LL << x);
         }
      }
      if(str == "check"){
         ll k = (S & (1LL<<x)) ? 1 : 0;
         cout << k << "\n";
      }
      if(str == "toggle"){
         S = S^(1LL<<x);
      }
      if(str == "all"){
         S = (1LL<<21)-2;
      }
      if(str == "empty"){
         S = 0;
      }
   }


   return 0;
}
