#include <bits/stdc++.h>
using namespace std;

int N;
int A[10];
int B[10];
int C[10];


bool check_AB(int i, int j, int k){
   bool ok = true;
   C[0] = i;
   C[1] = j;
   C[2] = k;
   for(int r=0; r<3; r++){
      int d = abs(A[r] - C[r]);
      if(min(d, N-d) > 2){
         ok = false;
         break;
      }
   }
   if(ok)   return true;
   ok = true;
   for(int r=0; r<3; r++){
      int d = abs(B[r] - C[r]);
      if(min(d, N-d) > 2){
         ok = false;
         break;
      }
   }
   return (ok) ? true : false;
}

int main(){
   int cnt = 0;
   scanf("%d", &N);
   scanf("%d %d %d", &A[0], &A[1], &A[2]);
   scanf("%d %d %d", &B[0], &B[1], &B[2]);
   for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
         for(int k=1; k<=N; k++){
            if(check_AB(i, j, k)){
               cnt++;
            }
         }
      }
   }
   printf("%d\n", cnt);
}
