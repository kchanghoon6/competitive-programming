#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1010][1010];
int main(){
  char A[1010];
  char B[1010];
  scanf("%s", A);
  scanf("%s", B);
  int lenA = strlen(A);
  int lenB = strlen(B);
  for(int i=1; i<=lenA; i++){
    for(int j=1; j<=lenB; j++){
      if(A[i-1] == B[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  printf("%d\n", dp[lenA][lenB]);
}
