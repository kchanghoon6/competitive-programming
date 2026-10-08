#include <stdio.h>
int arr[70][70]; // 64

void quadtree(int x, int y, int n){
  int temp = arr[y][x];
  bool isOneNum = true;
  for(int i=y; i<y+n; i++){
    for(int j=x; j<x+n; j++){
      if(temp != arr[i][j]){
        isOneNum = false;
        break;
      }
    }
    if(!isOneNum) break;
  }
  if(isOneNum){
    printf("%d", arr[y][x]);
    return;
  }
  else{
    printf("(");
    quadtree(x, y, n/2);
    quadtree(x+n/2, y, n/2);
    quadtree(x, y+n/2, n/2);
    quadtree(x+n/2, y+n/2, n/2);
    printf(")");
  }
}

int main (){
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      scanf("%1d", &arr[i][j]);
    }
  }
  quadtree(0, 0, N);
  printf("\n");
}
