#include <stdio.h>
int main(){
  int arr[1100];
  int dp[1100];
  int output[1100];
  int temp[1100];
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &arr[i]);
    output[i] = -1;
  }
  dp[0] = 1;
  for(int a=1; a<N; a++){
    int maxi = 0;
    for(int i=0; i<a; i++){
      if(dp[i] > maxi && arr[i] < arr[a]){
        maxi = dp[i];
        output[a] = i;
      }
    }
    dp[a] = maxi + 1;

  }
  // maxi 출력
  int maxi = dp[0];
  int maxi_ind = 0;
  for(int i=1; i<N; i++){
    if(dp[i] > maxi){
      maxi = dp[i];
      maxi_ind = i;
    }
  }
  printf("%d\n", maxi);
  int k=0;
  for(int i=maxi_ind; i != -1; i=output[i]){
    temp[k] = arr[i];
    k++;
  }
  for(int i=k-1; i>=0; i--){
    printf("%d ", temp[i]);
  }
  printf("\n");
}
