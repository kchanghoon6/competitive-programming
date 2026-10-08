#include <stdio.h>
int total=0;
int N;
void tiling(int a1, int a2, int n){
  if(N==1){
    total = a1%10007;
    return;
  }
  if(N==2){
    total = a2%10007;
    return;
  }
  if(n==N){
    total = (a1+a2)%10007;
    return;
  }
  tiling(a2%10007, (a1+a2)%10007, n+1);
}
int main(){
  scanf("%d", &N);
  tiling(1, 2, 3);
  printf("%d\n", total);
}
