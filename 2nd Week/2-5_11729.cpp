#include <stdio.h>
int N;
int count=0;
int array[10000000][3];
void Hanoi(int from, int to, int n){
  if(n == 1){
    array[count][0] = from;
    array[count][1] = to;
    count++;
    return;
  }
  Hanoi(from, 6-to-from, n-1);
  array[count][0] = from;
  array[count][1] = to;
  count++;
  Hanoi(6-to-from, to, n-1);
}

int main(){
  scanf("%d", &N);
  Hanoi(1, 3, N);
  printf("%d\n", count);
  for(int i=0; i<count; i++){
    printf("%d %d\n", array[i][0], array[i][1]);
  }
}
