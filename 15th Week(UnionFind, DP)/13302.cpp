#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[200][200];
ll A[200];

ll N, M;


int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=0; i<M; i++){
      ll a;
      scanf("%lld", &a);
      A[a] = 1;
   }
   for(ll i=0; i<=N+10; i++){
      for(ll j=0; j<=N; j++){
         dp[i][j] = 1e9;
      }
   }
   dp[0][0] = 0;
   for(ll i=0; i<=N; i++){
      for(ll j=0; j<=N; j++){
         dp[i+1][j] = min(dp[i][j]+10000, dp[i+1][j]);
         for(ll k=1; k<=3; k++){
            dp[i+k][j+1] = min(dp[i][j]+25000, dp[i+k][j+1]);
         }
         for(ll k=1; k<=5; k++){
            dp[i+k][j+2] = min(dp[i][j]+37000, dp[i+k][j+2]);
         }
         if(j >= 3){
            dp[i+1][j-3] = min(dp[i][j], dp[i+1][j-3]);
         }
         if(A[i+1]){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
         }
      }
   }
   // for(ll i=0; i<=N; i++){
   //    for(ll j=0; j<=5; j++){
   //       printf("%lld ", dp[i][j]);
   //    }
   //    printf("\n");
   // }

   ll mini = 1e9;
   for(ll i=0; i<=N; i++){
      mini = min(mini, dp[N][i]);
   }
   printf("%lld\n", mini);


   return 0;
}
