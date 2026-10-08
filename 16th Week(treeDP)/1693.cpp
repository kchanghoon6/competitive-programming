#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
vector<ll> G[200000];
ll dp[100005][150];

void make_tree(ll node, ll par){
   for(int j=1;j<=100;j++) dp[node][j] = j;
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      for(ll j=1; j<=100; j++){
         ll mini = 1e15;
         for(ll k=1; k<=100; k++){
            if(j == k)  continue;
            mini = min(mini, dp[i][k]);
         }
         dp[node][j] += mini;
      }
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
   ll mini = 1e15;
   for(ll i=1; i<=100; i++){
      mini = min(mini, dp[1][i]);
   }
   printf("%lld\n", mini);
   return 0;
}
