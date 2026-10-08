#include <stdio.h>
int main (){
  int n;
  int p=0;
  int i=1;
  scanf("%d", &n);

  while(true){
    if(5*i > n)
    {
      p+=i-1;
      n-=5*p;
      break;
    }
    else if(5*i == n)
    {
      p+=i;
      n-=5*p;
      break;
    }
    i++;
  }
  i=1;
  if(n>=3)
  {
    p+=i;
    n;
  }
  if(n==0)
    printf("%d", p);
  else
    printf("-1");
}
