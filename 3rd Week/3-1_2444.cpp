#include <stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    for(int k=i; k<=n-1; k++){
      printf(" ");
    }
    for(int j=1; j<=2*i-1; j++){
      printf("*");
    }
    if(i==1)
      printf("\n");
    else
      printf(" \n");
  }
  for(int i=n-1; i>=1; i--){
    for(int k=i; k<=n-1; k++){
      printf(" ");
    }
    for(int j=2*i-1; j>=1; j--){
      printf("*");
    }
    printf("\n");
  }
}
