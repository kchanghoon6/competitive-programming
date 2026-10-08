//backtracking version
#include <stdio.h>
int A[10];
int N, M;
void f(int i){
  if(i == M){
    for(int j=0; j<M; j++){
      printf("%d ", A[j]);
    }
    printf("\n");
    return;
  }
  for(int a=1; a<=N; a++){
    A[i] = a;
    f(i+1);
  }
}

int main (){
  scanf("%d %d", &N, &M);
  f(0);
}
