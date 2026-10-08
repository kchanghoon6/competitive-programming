#include <bits/stdc++.h>
using namespace std;
int main (){
   int n;
   scanf("%d", &n);
   int hour[5010];
   int minute[5010];
   int second[5010];
   for(int i=0; i<n; i++){
      scanf("%d %d %d", &hour[i], &minute[i], &second[i]);
   }
   for(int i=0; i<n; i++){
      for(int j=0; j<n-1; j++){
         if(hour[j] > hour[j+1]){
            swap(hour[j], hour[j+1]);
            swap(minute[j], minute[j+1]);
            swap(second[j], second[j+1]);
         }
         else if(hour[j] == hour[j+1]){
            if(minute[j] > minute[j+1]){
               swap(hour[j], hour[j+1]);
               swap(minute[j], minute[j+1]);
               swap(second[j], second[j+1]);
            }
            else if(minute[j] == minute[j+1]){
               if(second[j] > second[j+1]){
                  swap(hour[j], hour[j+1]);
                  swap(minute[j], minute[j+1]);
                  swap(second[j], second[j+1]);
               }
            }
         }
      }
   }
   for(int i=0; i<n; i++){
      printf("%d %d %d\n", hour[i], minute[i], second[i]);
   }
}
