#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N = 1, M = 1;
vector<pll> G[10010];
ll dist[10010];
vector<ll> P[10010];
ll visited[10010];

ll Dijkstra(ll st, ll e){
   priority_queue<pll, vector<pll>, greater<pll>> pq;
   pq.push({0, st});
   dist[st] = 0;
   while(!pq.empty()){
      pll v = pq.top();
      pq.pop();
      if(dist[v.ss] != v.ff)  continue;
      for(auto w : G[v.ss]){
         if(w.ss >= 1e10)  continue;
         if(!visited[w.ff] && dist[w.ff] > dist[v.ss] + w.ss){
            P[w.ff].clear();
            P[w.ff].push_back(v.ss);
            dist[w.ff] = dist[v.ss] + w.ss;
            pq.push({dist[w.ff], w.ff});
         }
         else if(!visited[w.ff] && dist[w.ff] == dist[v.ss] + w.ss){
            P[w.ff].push_back(v.ss);
         }
      }
   }
   return dist[e];
}

void BFS(ll st){
   queue<ll> q;
   q.push(st);
   visited[st] = 1;
   while(!q.empty()){
      ll v = q.front();
      q.pop();
      for(auto i : P[v]){
         for(auto &j : G[i]){
            if(j.ff == v && j.ss < 1e10){
               j.ss = 1e10;
            }
         }
         if(!visited[i]){
            visited[i] = 1;
            q.push(i);
         }
      }
   }
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   while(true){
      ll S, E;
      cin >> N >> M;
      if(N == 0 && M == 0) break;
      cin >> S >> E;
      for(ll i=0; i<N; i++){
         dist[i] = 1e15;
         visited[i] = 0;
         P[i].clear();
         G[i].clear();
      }
      for(ll i=0; i<M; i++){
         ll u, v, p;
         cin >> u >> v >> p;
         G[u].push_back({v, p});
      }
      Dijkstra(S, E);
      BFS(E);
      for(ll i=0; i<N; i++){
         dist[i] = 1e15;
         visited[i] = 0;
         P[i].clear();
      }
      ll ans = Dijkstra(S, E);
      if(ans >= 1e10) ans = -1;
      cout << ans << "\n";
   }

   return 0;
}
