#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll idx;
ll vt[20000];
vector<ll> G[20000];
set<ll> S;

ll dfs(ll node, ll par, ll root){
   vt[node] = ++idx;
   ll lo = vt[node];
   ll ch = 0;
   for(auto i : G[node]){
      if(i == par)   continue;
      if(vt[i])   lo = min(lo, vt[i]);
      else{
         ch++;
         ll d = dfs(i, node, 0);
         if((root && ch >=2) || (!root && d >= vt[node])){
            S.insert(node);
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
      if(!vt[i])  dfs(i, 0, 1);
   }
   cout << S.size() << "\n";
   for(auto i : S){
      cout << i << " ";
   }


   return 0;
}
