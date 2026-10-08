#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[100000];

int main(){
   scanf("%d %d", &N, &K);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   sort(A, A+N);
   int max_rad = (A[N-1]-A[1])/2*K + 1;
   int s = 1, e = max_rad;
   int ans;
   while(s <= e){
      int r = (s+e)/2;
      int d = 0;
      int cnt = 1;
      for(int i=0; i<N; i++){
         if(i == 0)  d = A[0] + 2*r;
         if(A[i] > d){
            d = A[i] + 2*r;
            cnt++;
         }
         if(cnt > K){
            s = r + 1;
            break;
         }
      }
      if(cnt <= K){
         ans = r;
         e = r - 1;
      }
   }
   printf("%d\n", ans);
   return 0;
}
