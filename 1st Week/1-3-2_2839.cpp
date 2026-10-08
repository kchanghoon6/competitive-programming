#include <stdio.h>
int main (){
  int n;
  int n2;
  int min;
  int p5=0;
  int p3=0;
  scanf("%d", &n);
  n2=n;

  while(n>2){
    for(int i=0; n/5-i>0; i++)
    {
      if(n>=5){
        p5+=n/5-i;
        n -= p5*5;
      }
      else if(n>=3){
        p3+=n/3;
        n-=p3*3;
      }
    }
  }
  if(n==0){
    printf("%d", p3+p5);
  }
  else if(n2>=3){
    p3=0;
    p3+=n2/3;
    n2-=p3*3;
    if(n2==0)
      printf("%d", p3);
    else
      printf("-1");
  }
}
