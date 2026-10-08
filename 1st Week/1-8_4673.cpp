#include <stdio.h>
int d(int n){
  int result = n;
  while(n>0){
    result += n%10;
    n /= 10;
  }
  return result;
}
int main (){
  int sign;
  int array[11000];
  for(int i=1; d(i)<10040; i++){
    array[i-1] = d(i);
  }
  for(int i=1; i<10000; i++){
    sign = 0;
    for(int j=1; d(j)<10040; j++){
      if(i == array[j-1]){
        sign = 1;
        break;
      }
    }
    if(sign == 0) printf("%d\n", i);
  }
  return 0;
}
