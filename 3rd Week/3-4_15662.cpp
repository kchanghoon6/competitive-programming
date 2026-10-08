#include <stdio.h>
int T, K;
int arr[1100][10];
int rotNum[1100][5];
int firstWh;
void rotate(int wh, int dir){
  if(dir == 1){
    int temp = arr[wh][7];
    for(int i=7; i>0; i--){
      arr[wh][i] = arr[wh][i-1];
    }
    arr[wh][0] = temp;
  }
  else{
    int temp = arr[wh][0];
    for(int i=0; i<7; i++){
      arr[wh][i] = arr[wh][i+1];
    }
    arr[wh][7] = temp;
  }
}
void incWay(int wh, int dir){
  int temp = arr[wh][2];
  rotate(wh, dir);
  if(wh < T-1 && temp != arr[wh+1][6]){
    incWay(wh+1, -dir);
  }
}
void decWay(int wh, int dir){
  int temp = arr[wh][6];
  rotate(wh, dir);
  if(wh > 0 && temp != arr[wh-1][2]){
    decWay(wh-1, -dir);
  }
}

int main(){
  int result=0;
  scanf("%d", &T);
  for(int i=0; i<T; i++){
    for(int j=0; j<8; j++){
      scanf("%1d", &arr[i][j]);
    }
  }
  scanf("%d", &K);
  for(int i=0; i<K; i++){
    scanf("%d %d", &rotNum[i][0], &rotNum[i][1]);
  }
  for(int i=0; i<K; i++){
    int wh = rotNum[i][0]-1;
    int dir = rotNum[i][1];

    int rPole = arr[wh][2];
    int lPole = arr[wh][6];
    rotate(wh, dir);
    if(wh<T-1 && rPole != arr[wh+1][6])
      incWay(wh+1, -dir);
    if(wh > 0 && lPole != arr[wh-1][2])
      decWay(wh-1, -dir);
  }
  for(int i=0; i<T; i++){
    if(arr[i][0] == 1)  result++;
  }
  printf("%d\n", result);
  return 0;
}
