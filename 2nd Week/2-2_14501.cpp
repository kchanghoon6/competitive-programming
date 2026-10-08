#include <stdio.h>
int T[20];
int P[20];
int N;
int maxP=0;
void twaesa(int day, int p){
  if(day >= N){
    if(p>maxP){
      maxP=p;
    }
    return;
  }
  if(day+T[day] <= N){
    twaesa(day+T[day], p+P[day]);
  }
  twaesa(day+1, p);
}
int main (){
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d %d", &T[i], &P[i]);
  }
  twaesa(0, 0);
  printf("%d\n", maxP);
  return 0;
}
