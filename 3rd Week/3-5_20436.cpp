#include <stdio.h>
#include <cmath>
char keyboard[3][15] = {{'q', 'w', 'e','r', 't', 'y', 'u', 'i', 'o', 'p'},
  {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
  {'z', 'x', 'c', 'v', 'b', 'n', 'm'}}; // 10*3
char input[150];
int row_length[3] = {10, 9, 7};
int r, c, rd, ld;
int min = 1000000000;
void twoDistance(int a, int curR[2], int curL[2]){
  for(int i=0; i<3; i++){
    for(int j=0; j<row_length[i]; j++){
      if(keyboard[i][j] == input[a]){
        rd = abs(i-curR[0]) + abs(j-curR[1]);
        ld = abs(i-curL[0]) + abs(j-curL[1]);
        r = i;
        c = j;
        return;
      }
    }
  }
}
void backtrack(int a, int curR[2], int curL[2], int total){
  if(input[a] == '\0'){
    if(min > total){
      min = total;
    }
    return;
  }
  twoDistance(a, curR, curL);
  int newR[2], newL[2];

  if((c>=5 && r<=1) || (r==2 && c>=4)){
    newR[0] = r;  newR[1] = c;
    newL[0] = curL[0]; newL[1] = curL[1];
    backtrack(a+1, newR, newL, total+rd+1);
  }
  else{
    newL[0] = r;  newL[1] = c;
    newR[0] = curR[0]; newR[1] = curR[1];
    backtrack(a+1, newR, newL, total+ld+1);
  }
}

int main (){
  char startL, startR;
  int curR[2];
  int curL[2];
  scanf("%c %c", &startL, &startR);
  scanf("%s", input);
  for(int i=0; i<3; i++){
    for(int j=0; j<row_length[i]; j++){
      if(keyboard[i][j] == startL){
        curL[0] = i;
        curL[1] = j;
      }
      if(keyboard[i][j] == startR){
        curR[0] = i;
        curR[1] = j;
      }
    }
  }
  backtrack(0, curR, curL, 0);
  printf("%d\n", min);
}
