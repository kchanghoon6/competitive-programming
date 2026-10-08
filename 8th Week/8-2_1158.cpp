#include <stdio.h>
#include <queue>
using namespace std;
int main(){
  int n, k;
  int arr[5010][2];
  scanf("%d %d", &n, &k);
  for(int i=0; i<=n; i++){
    arr[i][0] = i;
    arr[i][1] = 0;
  }
  // printf("<");
  int count = 0;
  int p = 0;
  for(int i=1; ; i++){
    int q = (i%n == 0) ? n : i%n;
    if(arr[q][1] != 1){
      p++;
    }
    if(p == k){
      count++;
      arr[q][1] = 1;
      // printf("%d", arr[q][0]);
      p = 0;
      if(count == n){
        printf("%d", i);
        break;
      }
      // else  printf(", ");
    }
  }
  // printf(">\n");
}
