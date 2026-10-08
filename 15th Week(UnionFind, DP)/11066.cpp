#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll T, K;
ll A[50000];
ll sum[700];
ll dp[700][700];
int main(){
   scanf("%lld", &T);
   while(T--){
      scanf("%lld", &K);
      for(ll i=1; i<=K; i++){
         scanf("%lld", &A[i]);
         sum[i] = sum[i-1]+A[i];
      }
      for(ll i=1; i<=K; i++){
         for(ll j=1; j<=K; j++){
            dp[i][j] = 1e15;
            dp[j][j] = 0;
         }
      }
      for(ll len=2; len<=K; len++){
         for(ll i=1; i+len-1<=K; i++){
            ll j = i+len-1;
            for(ll k=i; k<j; k++){
               dp[i][j] = min(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1], dp[i][j]);
            }
         }
      }
      printf("%lld\n", dp[1][K]);
      for(ll i=1; i<=K; i++){
         A[i] = 0;
      }
   }
   return 0;
}
