#include <stdio.h>
int main (){
  int n;
  int hold;
  int min;
  int array[1100];
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &array[i]);
  }
  /*  // bubble sort
  for(int i=0; i<n; i++){
    for(int j=0; j<n-1; j++){
      if(array[j] > array[j+1]){
        hold = array[j+1];
        array[j+1] = array[j];
        array[j] = hold;
      }
    }
  }
  */
  /* // insertion sort
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      if(array[i-j] < array[i-j-1]){
        hold = array[i-j-1];
        array[i-j-1] = array[i-j];
        array[i-j] = hold;
      }
    }
  }
  */
  // selection sort
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      if(array[i]<array[j]){
        hold = array[j];
        array[j] = array[i];
        array[i] = hold;
      }
    }
  }
  for(int i=0; i<n; i++){
    printf("%d\n", array[i]);
  }
}
