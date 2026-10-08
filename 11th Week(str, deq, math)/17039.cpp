#include <bits/stdc++.h>
using namespace std;

int main(){
   int A[100];
   scanf("%d %d %d", &A[0], &A[1], &A[2]);
   sort(A, A+3);
   int B[100];
   B[0] = A[1]-A[0];
   B[1] = A[2]-A[1];
   if(B[0] == 1 && B[1] == 1){
      printf("0\n");
   }
   else if(B[0] == 2 || B[1] == 2){
      printf("1\n");
   }
   else{
      printf("2\n");
   }
   printf("%d\n", max(B[0], B[1]) - 1);
   return 0;
}
