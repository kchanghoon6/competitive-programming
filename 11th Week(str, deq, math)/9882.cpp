#include <bits/stdc++.h>
using namespace std;
int A[100];
bool used[100];
int sum[100];
int mini = 1e9;
void min_diff(int teams){
   if(teams == 4){
      int sum_min = 1e9;
      int sum_max = 0;
      for(int i=0; i<4; i++){
         if(sum_min>=sum[i])  sum_min = sum[i];
         if(sum_max<=sum[i]) sum_max = sum[i];
      }
      mini = min(mini, sum_max-sum_min);
      return;
   }
   for(int i=0; i<12; i++){
      if(used[i])  continue;
      for(int j=i+1; j<12; j++){
         if(used[j])  continue;
         for(int k=j+1; k<12; k++){
            if(used[k])  continue;
            used[i] = used[j] = used[k] = true;
            sum[teams] = A[i] + A[j] + A[k];
            min_diff(teams+1);
            sum[teams] = 0;
            used[i] = used[j] = used[k] = false;
         }
      }
   }
}
int main(){
   for(int i=0; i<12; i++){
      scanf("%d", &A[i]);
   }
   min_diff(0);
   printf("%d\n", mini);
   return 0;
}
