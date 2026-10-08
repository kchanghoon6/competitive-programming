#include <bits/stdc++.h>
using namespace std;

int main(){
   int A, B, S;
   int cnt = 0;
   scanf("%d", &S);
   for(int i=S; ; i++){
      int sum = 0;
      for(int j=1; j*j<=i; j++){
         if(i % j == 0){
            sum += j + i/j;
            if(j*j == i)   sum -= j;
         }
      }
      sum -= i;
      if(i == sum)   continue;
      int sum2 = 0;
      for(int j=1; j*j <= sum; j++){
         if(sum % j == 0){
            sum2 += j + sum/j;
            if(j*j == sum)   sum2 -= j;
         }
      }
      sum2 -= sum;
      if(sum2 == i){
         printf("%d %d\n", i, sum);
         break;
      }
   }
   return 0;
}
