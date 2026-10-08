#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
vector<ll> G[(ll)2e6];
ll dp[(ll)2e6][5];

void make_tree(ll node, ll par){
   dp[node][0] = 0;
   dp[node][1] = 1;
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      dp[node][0] += dp[i][1];
      dp[node][1] += min(dp[i][0], dp[i][1]);
   }
}

int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   make_tree(1, 0);
   printf("%lld\n", min(dp[1][0], dp[1][1]));
   return 0;
}
