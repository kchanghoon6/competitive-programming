#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K;
ll dp[300][150000];
ll A[300][10];
int main(){
   scanf("%lld %lld", &N, &K);
   for(ll i=1; i<=N; i++){
      scanf("%lld %lld %lld %lld", &A[i][0], &A[i][1], &A[i][2], &A[i][3]);
   }
   for(ll i=0; i<=N; i++){
      for(ll j=0; j<=K; j++){
         dp[i][j] = -1e15;
      }
   }
   dp[0][0] = 0;
   for(ll i=1; i<=N; i++){
      for(ll j=0; j<=K; j++){
         if(j >= A[i][0]){
            dp[i][j] = max(dp[i][j], dp[i-1][j-A[i][0]]+A[i][1]);
         }
         if(j >= A[i][2]){
            dp[i][j] = max(dp[i][j], dp[i-1][j-A[i][2]]+A[i][3]);
         }
      }
   }
   ll maxi = 0;
   for(ll j=0; j<=K; j++){
      maxi = max(maxi, dp[N][j]);
   }
   printf("%lld\n", maxi);

   return 0;
}
