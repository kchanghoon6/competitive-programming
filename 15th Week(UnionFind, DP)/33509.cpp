#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N;
ll A[10000];
ll B[10000];
ll C[10000];
ll P[10000];
ll dp[8000][8000];
int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &A[i]);
   }
   for(ll i=1; i<=N; i++){
      scanf("%lld", &B[i]);
   }
   for(ll i=1; i<=N; i++){
      ll add = (A[i] == B[i]) ?  1 : 0;
      P[i] = P[i-1] + add;
      dp[i][i] = add;
   }
   for(ll i=1; i<=N; i++){
      for(ll l=1; l<=N; l++){
         ll r = l+i;
         if(r > N)  continue;
         ll add = (A[r] == B[l]);
         add += (A[l] == B[r]);
         dp[l][r] = dp[l+1][r-1] + add;
      }
   }
   for(ll i=1; i<=N; i++){
      for(ll j=i; j<=N; j++){
         C[P[N]-(P[j]-P[i-1]) + dp[i][j]]++;
      }
   }
   for(ll i=0; i<=N; i++){
      printf("%lld\n", C[i]);
   }
   return 0;
}
