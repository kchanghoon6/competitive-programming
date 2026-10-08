#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll t;
   cin >> t;
   while(t--){
      ll n, m; cin >> n >> m;
      vector<string> inp(m);
      vector<char> out(m);
      for(ll i=0; i<m; i++) cin >> inp[i] >> out[i];

      vector<ll> P(m);
      for(ll i=0; i<m; i++) P[i] = i;

      ll res = 0;
      while(!res){
         ll flag = 0;
         for(ll i=0; i<n; i++){
            set<char> S0, S1;
            vector<ll> G0, G1;
            for(auto j : P){
               if(inp[j][i] == '1'){
                  S1.insert(out[j]);
                  G1.push_back(j);
               } else{
                  S0.insert(out[j]);
                  G0.push_back(j);
               }
            }
            if(S0.size() <= 1 && S1.size() <= 1){
               res = 1;
               break;
            }
            if(S0.size() == 0 || S1.size() == 0) continue;
            if(S0.size() == 2 && S1.size() == 2) continue;
            if(S0.size() == 1){
               flag = 1;
               P = G1;
               break;
            }
            else{
               flag = 1;
               P = G0;
               break;
            }
         }
         if(!res && !flag) res = 2;
      }
      cout << (res == 1 ? "OK" : "LIE") << "\n";
   }
}
