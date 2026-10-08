#include <stdio.h>
int main(){
  int n;
  int elec[500][2];
  int temp[1][2];
  int max_length[110];
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &elec[i][0], &elec[i][1]);
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n-1; j++){
      if(elec[j][0] > elec[j+1][0]){
        int temp1 = elec[j][0];
        int temp2 = elec[j][1];
        elec[j][0] = elec[j+1][0];
        elec[j][1] = elec[j+1][1];
        elec[j+1][0] = temp1;
        elec[j+1][1] = temp2;
      }
    }
  }
  max_length[0] = 1;
  int maxi;
  for(int i=0; i<n; i++){
    maxi = 0;
    for(int j=0; j<i; j++){
      if(max_length[j] > maxi && elec[j][1] <= elec[i][1]){
        maxi = max_length[j];
      }
    }
    max_length[i] = maxi + 1;
  }
  maxi = 0;
  for(int i=0; i<n; i++){
    if(max_length[i] > maxi){
      maxi = max_length[i];
    }
  }
  printf("%d\n", n-maxi);
}
