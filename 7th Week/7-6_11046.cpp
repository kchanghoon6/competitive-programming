#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
  int A[1010][1010];
  int dp[1010][1010];
  int n, m;
  int sum = 0;
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &A[i][j]);
    }
  }
  for(int i=0; i<n; i++){
    sum += A[i][0];
    dp[i][0] = sum;
  }
  sum = 0;
  for(int j=0; j<m; j++){
    sum += A[0][j];
    dp[0][j] = sum;
  }
  for(int i=1; i<n; i++){
    for(int j=1; j<m; j++){
      dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + A[i][j];
    }
  }
  printf("%d\n", dp[n-1][m-1]);
}
