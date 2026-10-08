#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll N, M, C, R, K;
vector<pll> G[60000];
ll visits[60000];
set<ll> visited[60000];
ll dist[60000];

void Dijkstra(){
   priority_queue<pair<pll, ll>, vector<pair<pll, ll>>, greater<pair<pll, ll>>> pq;
   for(ll i=1; i<=C; i++){
      pq.push({{0, i}, i});
   }
   while(!pq.empty()){
      ll d = pq.top().ff.ff;
      ll v = pq.top().ff.ss;
      ll from = pq.top().ss;
      pq.pop();
      if(visits[v] == K)   continue;
      if(visited[v].count(from))   continue;
      visits[v]++;
      visited[v].insert(from);
      for(auto i : G[v]){
         if(d+i.ff <= R && visits[i.ss] < K){
            pq.push({{d+i.ff, i.ss}, from});
         }
      }
   }
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N >> M >> C >> R >> K;
   for(ll i=0; i<M; i++){
      ll a, b, c;
      cin >> a >> b >> c;
      G[a].push_back({c, b});
      G[b].push_back({c, a});
   }
   Dijkstra();
   ll cnt = 0;
   vector<ll> res;
   for(ll i=C+1; i<=N; i++){
      if(visits[i] == K){
         cnt++;
         res.push_back(i);
      }
   }
   cout << cnt << "\n";
   for(auto i : res){
      cout << i << "\n";
   }
   return 0;
}
