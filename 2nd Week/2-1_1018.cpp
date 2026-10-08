#include <stdio.h>
int main(){
  int n;
  int m;
  int k=0;
  int l=0;
  int num=0;
  int sum;
  int mini = 100;
  char wb1 = 'W';
  char wb2 = 'B';
  char array[50][51];
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++)
  {
    scanf("%s", array[i]);
  }
  while(num<2){
    for(int k=0; k<=n-8; k++){
      for(int l=0; l<=m-8; l++){
        sum=0;
        for(int i=k; i<k+8; i++){
          for(int j=l; j<l+8; j++){
            if(array[i][j] != (((i+j)%2) ? wb1 : wb2))
              sum++;
          }
        }
        if(mini>sum)
          mini = sum;
      }
    }
    wb1 = 'B';
    wb2 = 'W';
    num++;
  }
  printf("%d\n", mini);
  return 0;
}
