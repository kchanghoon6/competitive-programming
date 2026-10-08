#include <stdio.h>
int main(){
  int n, j;
  int total = 0;
  int count = 0;
  scanf("%d", &n);
  for(int i=0; total != n; i++){
    for(j=1; total + j*j<=n; j++){
    }
    j--;
    total += j*j;
    count++;
  }
  printf("%d\n", count);
}
