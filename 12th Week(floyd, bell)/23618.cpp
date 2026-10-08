#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll g[3000][3000];
ll N;
ll dist[3000];
vector<pll> A[3000];
priority_queue <pll, vector<pll>, greater<pll>> pq;
ll X[] = {1, -1, 0, 0};
ll Y[] = {0, 0, 1, -1};

void Dijkstra(ll st){
   for(ll i=1; i<=N; i++){
      dist[i] = 1e9;
   }
   while(!pq.empty())   pq.pop();
   dist[st] = 0;
   pq.push({0, st});
   while(!pq.empty()){
      pll v = pq.top();
      pq.pop();
      if(dist[v.ss] != v.ff)  continue;
      for(auto w : A[v.ss]){
         if(dist[w.ff] > dist[v.ss] + w.ss){
            dist[w.ff] = dist[v.ss] + w.ss;
            pq.push({dist[w.ff], w.ff});
         }
      }
   }
}

int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         scanf("%lld", &g[i][j]);
         if(g[i][j] == 1){
            A[i].push_back({j, 1});
         }
      }
   }
   Dijkstra(N);
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         if(g[i][j] > dist[i] + dist[j]){
            g[i][j] = dist[i] + dist[j];
         }
      }
   }
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         printf("%lld ", g[i][j]);
      }
      printf("\n");
   }

   return 0;
}
