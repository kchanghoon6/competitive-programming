#include <bits/stdc++.h>
using namespace std;
int N, d, k, c;
int A[40000];
int T[4000];
int t;
int main(){
   scanf("%d %d %d %d", &N, &d, &k, &c);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   int s = 0, e = 0;
   while(e < k){
      if(T[A[e]] == 0){
         t++;
      }
      T[A[e]]++;
      e++;
   }
   int maxi = t;
   if(T[c] == 0){
      maxi++;
   }
   while(s < N){
      T[A[s]]--;
      if(T[A[s]] == 0){
         t--;
      }
      s++;

      e = e % N;
      if(T[A[e]] == 0){
         t++;
      }
      T[A[e]]++;
      e++;
      int current = t;
      if(T[c] == 0){
         current++;
      }

      maxi = max(maxi, current);
   }
   printf("%d\n", maxi);
   return 0;
}
