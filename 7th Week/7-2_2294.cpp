#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[110][10010];
int A[110];
int main(){
  int n, k;
  const int INF = 100000000;
  scanf("%d %d", &n, &k);
  for(int i=1; i<=n; i++){
    scanf("%d", &A[i]);
  }
  dp[0][0] = 0;
  for(int i=1; i<=k; i++){
    dp[0][i] = INF;
  }
  for(int i=1; i<=n; i++){
    for(int j=0; j<=k; j++){
      if(j < A[i]) dp[i][j] = dp[i-1][j];
      else  dp[i][j] = min(dp[i-1][j], dp[i][j-A[i]] + 1);
    }
  }
  (dp[n][k] >= INF) ? printf("-1\n") : printf("%d\n", dp[n][k]);
}
