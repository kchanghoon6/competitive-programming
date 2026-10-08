#include <stdio.h>
#include <cmath>
int main (){
  int n;
  int dp[100000];
  scanf("%d", &n);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for(int i=3; i<=n; i++){
    int mini = 100000;
    for(int j=1; j<=sqrt(i); j++){
      if(mini > dp[j*j] + dp[i-j*j]){
        mini = dp[j*j] + dp[i-j*j];
      }
      if(j*j == i){
        mini = 1;
      }
      dp[i] = mini;
    }
  }
  printf("%d\n", dp[n]);
}
