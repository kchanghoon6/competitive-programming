#include <stdio.h>
// mergesort
int arr1[1000005]= {0};
int arr2[1000005]= {0};
void mergesort(int s, int e){
  if(e - s <= 1){
    return;
  }
  int half = (s+e)/2;
  mergesort(s, half);
  mergesort(half, e);
  int i = s;
  int j = half;
  int k;
  for(k=s; i<half && j<e; k++){
    if(arr1[i] <= arr1[j]){
      arr2[k] = arr1[i];
      i++;
    }
    else{
      arr2[k] = arr1[j];
      j++;
    }
  }
  while(i<half){
    arr2[k] = arr1[i];
    k++;
    i++;
  }
  while(j<e){
    arr2[k] = arr1[j];
    k++;
    j++;
  }
  for(int t=s; t<k; t++){
    arr1[t] = arr2[t];
  }
}

int main(){
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d", &arr1[i]);
  }
  mergesort(0, N);
  for(int i=0; i<N; i++){
    printf("%d\n", arr1[i]);
  }
}
