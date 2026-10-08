#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll idx;
ll vt[200000];
vector<ll> G[200000];
set<pll> S;

ll dfs(ll node, ll par){
   vt[node] = ++idx;
   ll lo = vt[node];
   for(auto i : G[node]){
      if(i == par)   continue;
      if(vt[i])   lo = min(lo, vt[i]);
      else{
         ll d = dfs(i, node);
         if(d > vt[node]){
            S.insert({min(node, i), max(node, i)});
         }
         lo = min(lo, d);
      }
   }
   return lo;
}

ll v, e;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> v >> e;
   for(ll i=0; i<e; i++){
      ll a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
   }
   for(ll i=1; i<=v; i++){
      if(!vt[i])  dfs(i, 0);
   }
   cout << S.size() << "\n";
   for(auto i : S){
      cout << i.ff << " " << i.ss << "\n";
   }


   return 0;
}
