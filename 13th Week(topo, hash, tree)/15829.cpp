#include <bits/stdc++.h>
#define ll long long
#define MOD 1234567891
using namespace std;

ll hash_function(ll a, string x){
   ll r = 1;
   ll ret = 0;
   for(auto i : x){
      ll b = i -'a'+1;
      ret += b*r;
      ret %= MOD;
      r*=31;
      r %= MOD;
   }
   return ret;
}
int main(){
   ll a;
   string x;
   cin >> a;
   cin >> x;
   cout << hash_function(a, x) << "\n";


   return 0;
}
