#include <bits/stdc++.h>
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;

int N, M;
vector<pll> lis[30000];    // pair<정점번호, 간선길이>
priority_queue<pll, vector<pll>, greater<pll>> pq; // pair<st로부터 길이, 정점번호>
stack<int> s;
int p_node[30000];
int dist[30000];
int maxi = -1;
int temp;

void doubling(int a, int b){
   for(auto &i : lis[a]){
      if(i.ff == b){
         i.ss *= 2;
      }
   }
   for(auto &i : lis[b]){
      if(i.ff == a){
         i.ss *= 2;
      }
   }
}

void restore(int a, int b){
   for(auto &i : lis[a]){
      if(i.ff == b){
         i.ss /= 2;
      }
   }
   for(auto &i : lis[b]){
      if(i.ff == a){
         i.ss /= 2;
      }
   }
}

void dijkstra(int st){
   for(int i = 1; i <= N; i++){
      dist[i] = 1000000000;
      p_node[i] = -1;
   }
   while(!pq.empty()) pq.pop();
   pq.push({0, st});
   dist[st] = 0;
   while(!pq.empty()){
      pll v = pq.top();
      pq.pop();
      if(dist[v.ss] != v.ff)  continue;
      for(auto i : lis[v.ss]){
         if(dist[i.ff] > dist[v.ss]+ i.ss){
            dist[i.ff] = dist[v.ss]+ i.ss;
            p_node[i.ff] = v.ss;
            pq.push({dist[i.ff], i.ff});
         }
      }
   }
}

int main(){
   scanf("%d %d", &N, &M);
   for(int i=1; i<=N; i++){
      p_node[i] = -1;
      dist[i] = 1000000000;
   }
   for(int i=1; i<=M; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      lis[a].push_back({b, c});
      lis[b].push_back({a, c});
   }
   dijkstra(1);
   int origin = dist[N];
   for(int i=N; i != -1; i=p_node[i]){
      s.push(i);
   }

   while(s.size() > 1){
      int a = s.top();
      s.pop();
      int b = s.top();
      doubling(a, b);
      dijkstra(1);
      maxi = max(maxi, dist[N]-origin);
      restore(a, b);
   }
   printf("%d\n", maxi);
   return 0;
}
