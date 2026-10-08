#include <stdio.h>
char arr[2500][2500];
void f(int n, int x, int y, bool is_center){
  if(is_center){
    for(int i=x; i<x+n; i++){
      for(int j=y; j<y+n; j++){
        arr[i][j] = ' ';
      }
    }
    return;
  }
  if(n==3){
    for(int i=x; i<x+3; i++){
      for(int j=y; j<y+3; j++){
        if(i==x+1 && j==y+1){
          arr[i][j] = ' ';
        }
        else{
          arr[i][j] = '*';
        }
      }
    }
    return;
  }
  f(n/3, x, y, false);
  f(n/3, x, y+n/3, false);
  f(n/3, x, y+2*n/3, false);
  f(n/3, x+n/3, y, false);
  f(n/3, x+n/3, y+n/3, true);
  f(n/3, x+n/3, y+2*n/3, false);
  f(n/3, x+2*n/3, y, false);
  f(n/3, x+2*n/3, y+n/3, false);
  f(n/3, x+2*n/3, y+2*n/3, false);
}
int main(){
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      arr[i][j] = ' ';
    }
  }
  f(N, 0, 0, false);
  for(int i=0; i<N; i++){
    printf("%s\n", arr[i]);
  }
}
