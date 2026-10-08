#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
int arr[100010];
int dp[100010][2];
void max_sum(int i){
  if(i == N){
    return;
  }
  dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
  dp[i][1] = max(dp[i-1][1], dp[i-1][0] - arr[i-1]) + arr[i];
  max_sum(i+1);
}

int main(){
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &arr[i]);
  }
  dp[0][0] = arr[0];
  dp[0][1] = arr[0];
  max_sum(1);
  int maxi = dp[0][0];
  for(int i=0; i<N; i++){
    if(dp[i][1] > maxi) maxi = dp[i][1];
  }
  printf("%d\n", maxi);
}
