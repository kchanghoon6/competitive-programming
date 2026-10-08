#include <stdio.h>
int N, M, num;
int R[1100];
int arr[110][110];
int arr2[110][110];
void save(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      arr[i][j] = arr2[i][j];
    }
  }
}
void r1(int arr[110][110]){
  for(int j=0; j<M; j++){
    for(int i=0; i<N/2; i++){
      int temp = arr[i][j];
      arr[i][j] = arr[N-1-i][j];
      arr[N-1-i][j] = temp;
    }
  }
}
void r2(int arr[110][110]){
  for(int i=0; i<N; i++){
    for(int j=0; j<M/2; j++){
      int temp = arr[i][j];
      arr[i][j] = arr[i][M-1-j];
      arr[i][M-1-j] = temp;
    }
  }
}
void r3(int arr[110][110]){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      arr2[j][N-1-i] = arr[i][j];
    }
  }
  int temp = N;
  N = M;
  M = temp;
  save();
}
void r4(int arr[110][110]){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      arr2[M-1-j][i] = arr[i][j];
    }
  }
  int temp = N;
  N = M;
  M = temp;
  save();
}
void r5(int arr[110][110]){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      arr2[i][j] = arr[i][j];
    }
  }
  for(int i=0; i<N/2; i++){
    for(int j=0; j<M/2; j++){
      arr[i][j+M/2] = arr2[i][j];
      arr[i+N/2][j+M/2] = arr2[i][j+M/2];
      arr[i+N/2][j] = arr2[i+N/2][j+M/2];
      arr[i][j] = arr2[i+N/2][j];
    }
  }
}
void r6(int arr[110][110]){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      arr2[i][j] = arr[i][j];
    }
  }
  for(int i=0; i<N/2; i++){
    for(int j=0; j<M/2; j++){
      arr[i+N/2][j] = arr2[i][j];
      arr[i][j] = arr2[i][j+M/2];
      arr[i][j+M/2] = arr2[i+N/2][j+M/2];
      arr[i+N/2][j+M/2] = arr2[i+N/2][j];
    }
  }
}
int main(){
  scanf("%d %d %d", &N, &M, &num);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  for(int i=0; i<num; i++){
    scanf("%d", &R[i]);
  }
  for(int i=0; i<num; i++){
    switch(R[i]){
    case 1:
      r1(arr);
      break;
    case 2:
      r2(arr);
      break;
    case 3:
      r3(arr);
      break;
    case 4:
      r4(arr);
      break;
    case 5:
      r5(arr);
      break;
    case 6:
      r6(arr);
      break;
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
