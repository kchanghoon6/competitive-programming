#include <bits/stdc++.h>
using namespace std;
int N;
int A[200000];
int main(){
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   sort(A, A+N);
   int s=0;
   int e=N-1;
   int mini = 2100000000;
   int se[50];

   while(s<e){
      int sum = A[s] + A[e];
      if(mini >= abs(sum)){
         se[0] = s;
         se[1] = e;
         mini = min(mini, abs(sum));
      }
      if(sum > 0){
         e--;
      }
      else if(sum < 0){
         s++;
      }
      else  break;
   }
   printf("%d %d\n", A[se[0]], A[se[1]]);

   return 0;
}
