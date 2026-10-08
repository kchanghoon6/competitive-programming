#include <bits/stdc++.h>
using namespace std;

int main(){
   int a, b, c, d;
   scanf("%d %d", &a, &b);
   scanf("%d %d", &c, &d);
   int result = 0;
   int lb = min(a, c);
   int ub = max(b, d);
   if(a <= d && c <= b){
      printf("%d\n", ub-lb);
   }
   else{
      printf("%d\n", b-a+d-c);
   }

   return 0;
}
