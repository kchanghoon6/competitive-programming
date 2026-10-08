#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, M, T;
ll total;
ll C[60000];
vector<pll> G[60000];
vector<ll> tree[60000];
priority_queue<pll, vector<pll>, greater<pll>> pq;
ll dist[60000];
ll dp[60000];
ll P[60000];
ll maxi = 0;

void Dijkstra(ll st){
   pq.push({0, st});
   dist[st] = 0;
   while(!pq.empty()){
      pll v = pq.top();
      pq.pop();
      if(dist[v.ss] != v.ff)  continue;
      for(auto w : G[v.ss]){
         if(dist[w.ss] > dist[v.ss] + w.ff){
            dist[w.ss] = dist[v.ss] + w.ff;
            P[w.ss] = v.ss;
            pq.push({dist[w.ss], w.ss});
         }
         else if(dist[w.ss] == dist[v.ss] + w.ff && v.ss < P[w.ss]){
            P[w.ss] = v.ss;
         }
      }
   }
}
void tree_dp(ll node, ll par){
   dp[node] = C[node];
   for(auto i : tree[node]){
      if(i == par)   continue;
      tree_dp(i, node);
      dp[node] += dp[i];
   }
   ll k = (dist[node]-T)*dp[node];
   maxi = max(maxi, k);
}


int main(){
   scanf("%lld %lld %lld", &N, &M, &T);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &C[i]);
      dist[i] = 1e15;
   }
   for(ll i=1; i<=M; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      G[a].push_back({c, b});
      G[b].push_back({c, a});
   }
   Dijkstra(1);
   for(ll i=1; i<=N; i++){
      total += (C[i]*dist[i]);
   }
   for(ll i=1; i<=N; i++){
      if(P[i] == 0)  continue;
      tree[P[i]].push_back(i);
   }
   tree_dp(1, 0);
   printf("%lld\n", maxi);

   return 0;
}
