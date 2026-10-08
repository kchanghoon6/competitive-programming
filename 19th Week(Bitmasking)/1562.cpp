#include <bits/stdc++.h>
#define ll long long
using namespace std;


const ll MOD = 1e9;
ll N;
ll dp[200][15][1500];
int main(){
   scanf("%lld", &N);
   for(ll j=1; j<=9; j++){
      dp[1][j][1LL<<j] = 1;
   }
   for(ll i=2; i<=N; i++){
      for(ll j=0; j<=9; j++){
         for(ll k=0; k<=(1LL<<10); k++){
            ll t = k|(1LL<<j);
            if(j >= 1)  dp[i][j][t] += dp[i-1][j-1][k];
            if(j <= 8)  dp[i][j][t] += dp[i-1][j+1][k];
            dp[i][j][t] %= MOD;
         }
      }
   }
   ll sum = 0;
   for(ll j=0; j<=9; j++){
      sum += dp[N][j][(1LL<<10)-1];
      sum %= MOD;
   }
   printf("%lld\n", sum);

   return 0;
}
