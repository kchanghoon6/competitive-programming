#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll n, m;
priority_queue<pll, vector<pll>, greater<pll>> pq;
ll dist[400000];
vector<pll> G[400000];

void dijkstra(ll st){
   for(ll i=1; i<=n; i++){
      dist[i] = 1e10;
   }
   dist[st] = 0;
   pq.push({0, st});
   while(!pq.empty()){
      auto v = pq.top();
      pq.pop();
      if(v.ff != dist[v.ss])  continue;
      for(auto w : G[v.ss]){
         if(dist[w.ff] > dist[v.ss]+w.ss){
            dist[w.ff] = dist[v.ss]+w.ss;
            pq.push({dist[w.ff], w.ff});
         }
      }
   }
}




int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll st;
   cin >> n >> m;
   cin >> st;

   for(ll i=0; i<m; i++){
      ll a, b, c;
      cin >> a >> b >> c;
      G[a].push_back({b, c});
   }
   dijkstra(st);
   for(ll i=1; i<=n; i++){
      if(dist[i] > 1e9){
         cout << "INF" << "\n";
         continue;
      }
      cout << dist[i] << "\n";
   }

   return 0;
}
