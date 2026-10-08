#include <stdio.h>
int Avail[1010];
int main(){
  int n;
  int arr[1010];
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  int maxi = 0;
  int count = 0;
  for(int i=n-1; i != 0; i = maxi){
    maxi = -1;
    for(int j=i-1; j>-1; j--){
      if(j + arr[j] >= i){
        maxi = j;
      }
    }
    if(maxi == -1){
      printf("-1");
      break;
    }
    count++;
  }
  if(maxi != -1){
    printf("%d\n", count);
  }
}
