#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll t;
vector<ll> G[2000];
set<pll> S;
ll vt[2000];
ll idx, no;

ll dfs(ll node, ll par){
   vt[node] = ++idx;
   ll lo = vt[node];
   for(auto i : G[node]){
      if(i == par)   continue;
      if(vt[i]){
         lo = min(lo, vt[i]);
         if(vt[node] > vt[i]){
            S.insert({node, i});
         }
      }
      else{
         S.insert({node, i});
         ll k = dfs(i, node);
         lo = min(lo, k);
         if(k > vt[node]){
            no = 1;
            return 0;
         }
      }
   }
   return lo;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> t;
   while(t--){
      ll n, m;
      cin >> n >> m;
      no = 0; idx = 0;
      S.clear();
      for(ll i=1; i<=n; i++){
         G[i].clear();
         vt[i] = 0;
      }
      for(ll i=0; i<m; i++){
         ll a, b;
         cin >> a >> b;
         G[a].push_back(b);
         G[b].push_back(a);
      }
      for(ll i=1; i<=n; i++){
         if(!vt[i]){
            dfs(i, 0);
            if(no){
               cout << "NO\n";
               break;
            }
         }
      }
      if(no)   continue;
      cout << "YES\n";
      for(auto i : S){
         cout << i.ff << " " << i.ss << "\n";
      }
   }
   return 0;
}
