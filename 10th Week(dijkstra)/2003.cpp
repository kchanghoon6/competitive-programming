#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[20000];

int main(){
   scanf("%d %d", &N, &M);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   int s = 0;
   int e = 0;
   int sum = A[s];
   int cnt = 0;
   while(e < N){
      if(sum < M){
         e++;
         if(e < N) sum += A[e];
      }
      else if(sum > M){
         s++;
         if(s > e){
            e = s;
            if(e < N) sum = A[e];
         }
         else{
            sum -= A[s-1];
         }
      }
      else{
         cnt++;
         s++;
         if(s > e){
            e = s;
            if(e < N) sum = A[e];
         }
         else{
            sum -= A[s-1];
         }
      }
   }
   printf("%d\n", cnt);
   return 0;
}
