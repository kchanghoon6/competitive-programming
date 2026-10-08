#include <bits/stdc++.h>
using namespace std;

int K;
int x_num[20000];
int y_num[20000];
int main(){
   scanf("%d", &K);
   for(int i=0; i<K; i++){
      scanf("%d %d", &x_num[i], &y_num[i]);
   }
   for(int i=0; i<K; i++){
      for(int j=10; j<=15000; j++){
         int hund = (x_num[i]/100);
         int ten = (x_num[i]/10);
         int x_dec = (x_num[i]%10) + (ten-(10*hund))*j + (hund*j*j);

         int s = 10;
         int e = 15000;
         while(s <= e){
            int mid = (s+e)/2;
            int hund2 = (y_num[i]/100);
            int ten2 = (y_num[i]/10);

            int y_dec = (y_num[i]%10) + (ten2-(10*hund2))*mid + (hund2*mid*mid);
            if(y_dec < x_dec){
               s = mid + 1;
            }
            else if(y_dec > x_dec){
               e = mid - 1;
            }
            else{
               printf("%d %d\n", j, mid);
               break;
            }
         }
      }
   }
}
