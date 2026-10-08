#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;


ll N, K;
vector<ll> G[200000];
ll C[200000];
ll dp[200000][10];

void make_tree(ll node, ll par){
   for(ll i=1; i<=3; i++){
      if(C[node] != 0){
         dp[node][i] = (C[node] == i) ? 1 : 0;
      }
      else{
         dp[node][i] = 1;
      }
   }

   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      for(ll j=1; j<=3; j++){
         if(!dp[node][j])  continue;
         ll p = 0;
         for(ll k=1; k<=3; k++){
            if(j == k)  continue;
            p += dp[i][k];
            p %= MOD;
         }
         dp[node][j] *= p;
         dp[node][j] %= MOD;
      }
   }


}



int main(){
   scanf("%lld %lld", &N, &K);
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   for(ll i=1; i<=K; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      C[a] = b;
   }
   make_tree(1, 0);
   printf("%lld\n", (dp[1][1]+dp[1][2]+dp[1][3])%MOD);
   return 0;
}
