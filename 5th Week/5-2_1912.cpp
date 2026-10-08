#include <stdio.h>
int N;
int arr[100010];
int dp[100010];
void max_sum(int i){
  if(i == N){
    return;
  }
  dp[i] = (dp[i-1] > 0) ? dp[i-1] + arr[i] : arr[i];
  max_sum(i+1);
}

int main(){
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &arr[i]);
  }
  dp[0] = arr[0];
  max_sum(1);
  int maxi = dp[0];
  for(int i=1; i<N; i++){
    if(dp[i] > maxi){
      maxi = dp[i];
    }
  }
  printf("%d\n", maxi);
}
