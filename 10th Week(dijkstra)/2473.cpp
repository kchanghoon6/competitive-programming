#include <bits/stdc++.h>
using namespace std;

int N;
int A[10000];
int main(){
   int se[10];
   long long mini = (long long) 4e10;
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   sort(A, A+N);
   for(int i=N-1; i>=2; i--){
      int v = i;
      int s = 0;
      int e = i-1;
      while(s<e){
         long long sum = (long long)A[s] + A[e] + A[v];
         if(mini >= abs(sum)){
            se[0] = s;
            se[1] = e;
            se[2] = v;
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
   }
   printf("%d %d %d\n", A[se[0]], A[se[1]], A[se[2]]);

   return 0;
}
