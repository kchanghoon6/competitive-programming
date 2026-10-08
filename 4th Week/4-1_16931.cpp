#include <stdio.h>
int main (){
  int N, M;
  int arr[110][110];
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  int A = 2*N*M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      for(int k=0; k<arr[i][j]; k++){
        A++;
      }
      if(j>0){
        if(arr[i][j]-arr[i][j-1]<0){
          A -= arr[i][j];
        }
        else{
          A -= arr[i][j-1];
        }
      }
    }
  }
  for(int i=0; i<N; i++){
    for(int j=M-1; j>-1; j--){
      for(int k=0; k<arr[i][j]; k++){
        A++;
      }
      if(j<M-1){
        if(arr[i][j]-arr[i][j+1]<0){
          A -= arr[i][j];
        }
        else{
          A -= arr[i][j+1];
        }
      }
    }
  }
  for(int j=0; j<M; j++){
    for(int i=N-1; i>-1; i--){
      for(int k=0; k<arr[i][j]; k++){
        A++;
      }
      if(i<N-1){
        if(arr[i][j]-arr[i+1][j]<0){
          A -= arr[i][j];
        }
        else{
          A -= arr[i+1][j];
        }
      }
    }
  }
  for(int j=0; j<M; j++){
    for(int i=0; i<N; i++){
      for(int k=0; k<arr[i][j]; k++){
        A++;
      }
      if(i>0){
        if(arr[i][j]-arr[i-1][j]<0){
          A -= arr[i][j];
        }
        else{
          A -= arr[i-1][j];
        }
      }
    }
  }
  printf("%d\n", A);

}
