#include <stdio.h>
#include <algorithm>
using namespace std;
int total = 0;
int N;
int house[1000][3];
int dp[1000][3];
void min_cost(int a){
  if(a==N){
    total = min(dp[a-1][0], min(dp[a-1][1], dp[a-1][2]));
    return;
  }
  dp[a][0] = house[a][0] + min(dp[a-1][1], dp[a-1][2]);
  dp[a][1] = house[a][1] + min(dp[a-1][0], dp[a-1][2]);
  dp[a][2] = house[a][2] + min(dp[a-1][0], dp[a-1][1]);
  min_cost(a+1);
}
int main(){
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    for(int j=0; j<3; j++){
      scanf("%d", &house[i][j]);
    }
  }
  for(int i=0; i<3; i++){
    dp[0][i] = house[0][i];
  }
  min_cost(1);
  printf("%d\n", total);
}
