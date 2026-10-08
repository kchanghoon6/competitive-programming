#include <stdio.h>
int main (){
  int n;
  int n_backup;
  int p;
  int tot_p=0;
  scanf("%d", &n);
  n_backup = n;
  for(int i=0; n/5-i>=0; i++)
  {
    p = n/5-i;
    n -= p*5;
    tot_p = p;
    p=0;
    if(n!=0){
      p = n/3;
      n -= p*3;
      if(n==0){
        tot_p += p;
        printf("%d", tot_p);
        break;
      }
    }
    else{
      printf("%d", tot_p);
      break;
    }
    n=n_backup;
  }
  if(n!=0)
    printf("-1");
}
