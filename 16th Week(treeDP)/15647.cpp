#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N;
vector<pll> G[500000];
ll P[500000];
ll D[500000];
ll C[500000];
ll indegree[500000];    // indegree 가중치
ll dp[500000];

ll make_tree(ll node, ll par, ll depth){
   P[node] = par;
   D[node] = D[par] + depth;
   C[node] = 1;
   for(auto i : G[node]){
      if(i.ff == par)   continue;
      indegree[i.ff] = i.ss;
      C[node] += make_tree(i.ff, node, i.ss);
   }
   return C[node];
}

void min_dist_sum(ll node){
   for(auto i : G[node]){
      if(i.ff == P[node])  continue;
      ll child = i.ff;
      ll c = indegree[child];
      ll k = C[child];
      dp[child] = dp[P[child]] - c*k + c*(N-k);
      min_dist_sum(child);
   }
}

int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N-1; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      G[a].push_back({b, c});
      G[b].push_back({a, c});
   }
   make_tree(1, 0, 0);

   ll sum = 0;
   for(ll i=1; i<=N; i++){
      sum += D[i];
   }
   dp[1] = sum;
   min_dist_sum(1);
   for(ll i=1; i<=N; i++){
      printf("%lld\n", dp[i]);
   }

   return 0;
}
