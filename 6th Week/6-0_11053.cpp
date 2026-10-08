#include <stdio.h>
int main(){
  int arr[1100];
  int dp[1100];
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &arr[i]);
  }
  dp[0] = 1;
  for(int a=1; a<N; a++){
    int maxi = 0;
    for(int i=0; i<a; i++){
      if(dp[i] > maxi && arr[i] < arr[a]){
        maxi = dp[i];
      }
    }
    dp[a] = maxi + 1;
  }
  int maxi = dp[0];
  for(int i=1; i<N; i++){
    if(dp[i] > maxi){
      maxi = dp[i];
    }
  }
  printf("%d\n", maxi);
}
