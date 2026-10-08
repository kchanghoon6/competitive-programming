#include <stdio.h>
#include <cmath>
int N, num;
char arr[500000][500000];
void poster(int n, int x, int y){
  if(n==1){
    arr[num-1][num-1] = 'J';
    return;
  }
  for(int i=x; i<x+n/2; i++){
    for(int j=y; j<y+n/2; j++){
      arr[i][j] = 'J';
      arr[i][j+n/2] = 'O';
      arr[i+n/2][j] = 'I';
    }
  }
  poster(n/2, x+n/2, y+n/2);
}
int main (){
  int K;
  scanf("%d %d", &N, &K);
  num = (int)pow(2, N);
  poster(num, 0, 0);
  printf("%s\n", arr[K-1]);
}
