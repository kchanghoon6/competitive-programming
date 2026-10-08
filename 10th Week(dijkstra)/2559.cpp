#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[200000];

int main(){
   scanf("%d %d", &N, &K);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   int s = 0, e = 0, sum = 0, maxi = -1e9;
   while(e-s+1 <= K){
      sum += A[e];
      e++;
   }
   e--;
   while(e < N-1){
      maxi = max(maxi, sum);
      sum -= A[s];
      s++;
      e++;
      sum += A[e];
   }
   maxi = max(maxi, sum);
   printf("%d\n", maxi);

   return 0;
}
