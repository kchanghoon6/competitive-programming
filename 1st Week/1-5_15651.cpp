#include <stdio.h>
#include <cmath>
int main(){
  int m;
  int n;
  scanf("%d %d", &n, &m);
  int k=m-1;
  int t = 0;
  int array[7];
  for(int i=0; i<m; i++)
    array[i] = 1;
  while(t<(int)pow(n, m))
  {
    for(int i=0; i<m; i++){
      printf("%d ", array[i]);
    }
    printf("\n");
    array[k]++;
    if(array[k] > n){
      array[k] = 1;
      while(k>-1)
      {
        k--;
        if(array[k] < n){
          array[k]++;
          break;
        }
        else{
          array[k] = 1;
        }
      }
      k=m-1;
    }
    t++;
  }
  return 0;
}
