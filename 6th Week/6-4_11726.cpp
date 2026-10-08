#include <stdio.h>
int main(){
  int n;
  int a1 = 1;
  int a2 = 3;
  int a3, temp;
  scanf("%d", &n);
  for(int i=2; i<n; i++){
    a3 = (2*a1 + a2)%10007;
    temp = a2;
    a2 = a3 % 10007;
    a1 = temp % 10007;
  }
  if(n == 1)  printf("%d\n", a1);
  else if(n == 2)  printf("%d\n", a2);
  else  printf("%d\n", a3);


}
