#include <stdio.h>
int N, K; // n/2 반복...
int num = 1;
void poster(int n, int x, int past_half){
  if(n==1){
    if(num == K){
      printf("J");
    }
    return;
  }
  if(K-1 >= past_half){
    if(K-1 < past_half + n/2){
      for(int i=x; i<x+n; i++){
        if(i < x+n/2){
          printf("J");
        }
        else{
          printf("O");
        }
      }
    }
    else{
      for(int i=x; i<x+n/2; i++){
        printf("I");
      }
    }
  }
  else  return;
  poster(n/2, x+n/2, past_half+n/2);
}
int main (){
  scanf("%d %d", &N, &K);
  for(int i=0; i<N; i++){
    num *= 2;
  }
  poster(num, 0, 0);
  printf("\n");
}
