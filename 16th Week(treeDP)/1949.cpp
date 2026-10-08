#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll A[50000];
ll P[50000];
vector<ll> G[50000];
ll dp[50000][5];

void make_tree(ll node, ll par){
   P[node] = par;
   dp[node][0] = 0;
   dp[node][1] = A[node];
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      dp[node][0] += max(dp[i][0], dp[i][1]);
      dp[node][1] += dp[i][0];
   }
}

int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &A[i]);
   }
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   make_tree(1, 0);
   printf("%lld\n", max(dp[1][0], dp[1][1]));
   return 0;
}
