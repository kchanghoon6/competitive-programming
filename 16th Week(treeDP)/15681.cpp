#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, R, Q;
vector<ll> G[200000];
ll dp[200000];


void make_tree(ll node, ll par){
   dp[node] = 0;
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      dp[node] += (dp[i]+1);
   }
}

int main(){
   scanf("%lld %lld %lld", &N, &R, &Q);

   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   make_tree(R, 0);
   for(ll i=1; i<=Q; i++){
      ll a;
      scanf("%lld", &a);
      printf("%lld\n", dp[a]+1);
   }

   return 0;
}
