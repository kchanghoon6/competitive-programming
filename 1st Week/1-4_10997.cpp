#include <stdio.h>
int main (){
  int n;
  int i=0;
  char array[399][397];
  int x=0;
  int y=0;
  int temp=0;
  scanf("%d", &n);
  for(int i=0; i<4*n-1; i++){
    for(int j=0; j<4*n-3; j++){
      array[i][j] = ' ';
    }
  }
  while(true){
    if(i>0)  temp = 1;
    for(x=4*n-4-2*i+temp; x>-1+2*i; x--){
      array[y][x] = '*';
    }
    x++;
    for(y=2*i; y<4*n-1-2*i; y++){
      array[y][x] = '*';
    }
    if(i==n-1)
      break;
    y--;
    for(x=2*i; x<4*n-3-2*i; x++){
      array[y][x] = '*';
    }
    x--;
    for(y=4*n-2-2*i; y>-1+2*(i+1); y--){
      array[y][x] = '*';
    }
    y++;
    i++;
  }
  if(n==1)
    printf("*\n");
  else{
    for(int i=0; i<4*n-1; i++){
      for(int j=0; j<4*n-3; j++){
        printf("%c", array[i][j]);
        if(i==1)  break;
      }
      printf("\n");
    }
  }
}
