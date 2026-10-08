#include <stdio.h>
int main(){
  int N, M;
  int arr[110][110];
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &arr[i][j]);
    }
  }
}
