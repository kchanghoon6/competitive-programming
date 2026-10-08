#include <stdio.h>
long long dp[210][210];
int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  for(int j=0; j<=k; j++){
    dp[0][j] = 1;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=k; j++){
      for(int a=i; a>=0; a--){
        dp[i][j] = (dp[i][j] + dp[a][j-1]) %1000000000;
      }
    }
  }
  printf("%lld\n", dp[n][k]);
}
