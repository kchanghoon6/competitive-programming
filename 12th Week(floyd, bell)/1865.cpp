#include <bits/stdc++.h>
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;

int N, M, W;
vector<pair<pll, int>> A;
int dist[1000];

bool bellman_ford(int st){
   for(int i=1; i<=N; i++){
      dist[i] = 1e9;
   }
   dist[st] = 0;
   for(int i=1; i<=N; i++){
      for(auto j : A){
         pll v = j.ff;
         if(dist[v.ss] > dist[v.ff] + j.ss){
            if(i==N)  return 1;
            dist[v.ss] = dist[v.ff] + j.ss;
         }
      }
   }
   return 0;
}

int main(){
   int T;
   scanf("%d", &T);
   while(T--){
      A.clear();
      scanf("%d %d %d", &N, &M, &W);
      for(int i=0; i<M; i++){
         int a, b, c;
         scanf("%d %d %d", &a, &b, &c);
         A.push_back({{a, b}, c});
         A.push_back({{b, a}, c});
      }
      for(int i=0; i<W; i++){
         int a, b, c;
         scanf("%d %d %d", &a, &b, &c);
         A.push_back({{a, b}, -c});
      }
      (bellman_ford(1)) ? printf("YES\n") : printf("NO\n");
   }
   return 0;
}
