#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b, ll m){
   ll r = 1; a %= m;
   while(b > 0){
      if(b & 1) r = r * a % m;
      a = a * a % m;
      b >>= 1;
   }
   return r;
}

int main(){
   ios::sync_with_stdio(0); cin.tie(0);
   ll iv = pw(2, MOD - 2, MOD);
   int T;
   cin >> T;
   while(T--){
      string s;
      cin >> s;
      bool bn = true;
      for(char c : s)
         if(c != '0' && c != '1'){ bn = false; break; }
      string b;
      if(bn) b = s;
      else for(char c : s) b += ((c - '0') % 2) ? '1' : '0';
      int st = 0;
      while(st < (int)b.size() - 1 && b[st] == '0') st++;
      b = b.substr(st);
      if(b == "0"){
         cout << (bn ? 0 : 1) << "\n";
         continue;
      }
      ll k = 0;
      for(char c : b) k = (2 * k + (c - '0')) % MOD;
      ll lb = b.back() - '0';
      ll g = (3 * k % MOD - lb + MOD) % MOD * iv % MOD;
      cout << (bn ? g : (g + 1) % MOD) << "\n";
   }
   return 0;
}
