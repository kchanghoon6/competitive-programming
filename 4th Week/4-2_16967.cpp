#include <stdio.h>
int H, W, X, Y;
int A[400][400];
int B[700][700];
void recover(){
  for(int i=0; i<X; i++){
    for(int j=0; j<W; j++){
      A[i][j] = B[i][j];
    }
  }
  for(int i=X; i<H; i++){
    for(int j=0; j<Y; j++){
      A[i][j] = B[i][j];
    }
  }
  for(int i=X; i<H; i++){
    for(int j=Y; j<W; j++){
      A[i][j] = B[i][j] - A[i-X][j-Y];
    }
  }
}

int main(){
  scanf("%d %d %d %d", &H, &W, &X, &Y);
  for(int i=0; i<H+X; i++){
    for(int j=0; j<W+Y; j++){
      scanf("%d", &B[i][j]);
    }
  }
  recover();
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(i==H-1 && j==W-1)  printf("%d", A[i][j]);
      else  printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}
