#include <stdio.h>
int result;
void fibonacci(int a1, int a2, int n){
  if(n==1){
    result = a1 + a2;
    return;
  }
  fibonacci(a2, a1+a2, n-1);
}
int main (){
  int N;
  scanf("%d", &N);
  if(N==0 || N==1)
    printf("%d\n", N);
  else{
    fibonacci(0, 1, N-1);
    printf("%d\n", result);
  }
}
