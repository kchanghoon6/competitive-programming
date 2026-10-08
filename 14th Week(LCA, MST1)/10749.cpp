#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N;
ll A[10000];
vector<pll> G[10000];
priority_queue<pll> pq;
ll tree[10000];
int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &A[i]);
   }
   for(ll i=1; i<=N; i++){
      for(ll j=i+1; j<=N; j++){
         ll weight = A[i]^A[j];
         G[i].push_back({weight, j});
         G[j].push_back({weight, i});
      }
   }
   for(auto i : G[1]){
      pq.push(i);
   }
   tree[1] = 1;
   ll weight = 0;
   while(!pq.empty()){
      auto e = pq.top();
      pq.pop();
      if(tree[e.ss]) continue;
      tree[e.ss] = 1;
      weight += e.ff;
      for(auto i : G[e.ss]){
         if(tree[i.ss]) continue;
         pq.push(i);
      }
   }
   printf("%lld\n", weight);
   return 0;
}
