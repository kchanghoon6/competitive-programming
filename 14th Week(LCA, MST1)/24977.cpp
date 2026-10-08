#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N;
ll G[200000];
ll V[200000];
ll indegree[200000];
queue<ll> q;
int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld %lld", &G[i], &V[i]);
      indegree[G[i]]++;
   }
   ll weight = 0;
   for(ll i=1; i<=N; i++){
      if(indegree[i] == 0){
         q.push(i);
      }
   }
   while(!q.empty()){
      auto e = q.front();
      q.pop();
      weight += V[e];
      if(--indegree[G[e]] == 0){
         q.push(G[e]);
      }
   }
   for(ll i=1; i<=N; i++){
      if(indegree[i] != 0){
         ll mini = V[i];
         ll cnt = V[i];
         ll node = i;
         node = G[i];
         indegree[i] = 0;
         while(node != i){
            cnt += V[node];
            mini = min(V[node], mini);
            indegree[node] = 0;
            node = G[node];
         }
         weight += (cnt-mini);
      }
   }
   printf("%lld\n", weight);

   return 0;
}
