#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[110][100010];
int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  int W[110];
  int V[110];
  for(int i=0; i<n; i++){
    scanf("%d %d", &W[i], &V[i]);
  }
  for(int i=0; i<=k; i++){
    dp[0][i] = (W[0] <= i) ? V[0] : 0;
  }
  for(int i=1; i<n; i++){
    for(int j=0; j<=k; j++){
      dp[i][j] = dp[i-1][j];
      if(j >= W[i]) dp[i][j] = max(dp[i-1][j-W[i]] + V[i], dp[i][j]);
    }
  }
  printf("%d\n", dp[n-1][k]);

}
