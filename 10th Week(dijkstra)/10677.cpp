#include <bits/stdc++.h>
#define ll long long
using namespace std;
int K;
int x_num;
int y_num;

bool isInteger(double N){
   return N == floor(N);
}
int main(){
   scanf("%d", &K);
   for(int i=0; i<K; i++){
      scanf("%d %d", &x_num, &y_num);
   }
   int b = max(x_num, y_num);
   int s = min(x_num, y_num);
   for(int i=10; i<=15000; i++){
      int hund = b/100;
      int tenth = b/10-hund*10;
      int one = b%10;
      ll b_ibase = hund*i*i + tenth*i + one;
      int a = s/100;
      int b = s/10-a*10;
      int c = s%10;
      if(sqrt(b*b-4*a*(c-b_ibase)) < 0)   continue;
      double j = (-b+sqrt(b*b-4*a*(c-b_ibase)))/2*a;
      if( isInteger(j) && j >= 10 && j <= 15000){
         printf("%d %.0f\n", i, j);
         break;
      }
   }
   return 0;
}
