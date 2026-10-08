#include <bits/stdc++.h>
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;

int N, M, X;
int cow_time[10000];
vector<pll> lis[60000];
priority_queue<pll, vector<pll>, greater<pll>> pq;
int dist[60000];

void dijkstra(int st){
   for(int i=1; i<=N; i++){
      dist[i] = 1000000000;
   }
   while(!pq.empty())   pq.pop();
   pq.push({0, st});
   dist[st] = 0;
   while(!pq.empty()){
      pll v = pq.top();
      pq.pop();
      if(dist[v.ss] != v.ff)  continue;
      for(auto i : lis[v.ss]){
         if(dist[i.ff] > dist[v.ss] + i.ss){
            dist[i.ff] = dist[v.ss] + i.ss;
            pq.push({dist[i.ff], i.ff});
         }
      }
   }
}


int main(){
   scanf("%d %d %d", &N, &M, &X);
   for(int i=1; i<=M; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      lis[a].push_back({b, c});
   }

   for(int i=1; i<=N; i++){
      dijkstra(i);
      cow_time[i] += dist[X];
   }
   dijkstra(X);
   for(int i=1; i<=N; i++){
      cow_time[i] += dist[i];
   }
   int maxi = -1;
   for(int i=1; i<=N; i++){
      maxi = max(cow_time[i], maxi);
   }
   printf("%d\n", maxi);
   return 0;
}
