#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, K, R;
set<pll> G;
vector<pair<ll, ll>> A;
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> N;
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      cin >> a >> b;
      G.insert({a, b});
      G.insert({b, a});
   }
   R = (N >= 5) ? 2 : 1;
   if(R == 1){
      for(ll i=1; i<=N; i++){
         for(ll j=i+1; j<=N; j++){
            if(G.find({i, j}) == G.end()){
               K++;
               A.push_back({i, j});
            }
         }
      }
   }
   else{
      for(ll i=2; i<=N; i++){
         if(G.find({1, i}) != G.end()) continue;
         K++;
         A.push_back({1, i});
      }
   }
   cout << K << "\n";
   cout << R << "\n";
   for(auto i : A){
      cout << i.ff << " " << i.ss << "\n";
   }

   return 0;
}
