#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

vector<pll> G[2000];
priority_queue <pll, vector<pll>, greater<pll>> pq;
ll tree[2000];
ll N, M;
int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=0; i<M; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      G[a].push_back({c, b});
      G[b].push_back({c, a});
   }
   tree[1] = 1;
   for(auto i : G[1]){
      pq.push(i);
   }
   ll weight = 0;
   while(!pq.empty()){
      pll e = pq.top();
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
