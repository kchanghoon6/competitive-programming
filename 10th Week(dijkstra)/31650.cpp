#include <bits/stdc++.h>
using namespace std;
int N, Q;
int C[2000000];
int T[2000000];
int V[2000000];
int S[2000000];

int D[2000000];
int main(){
   scanf("%d %d", &N, &Q);
   for(int i=0; i<N; i++){
      scanf("%d", &C[i]);
   }
   for(int i=0; i<N; i++){
      scanf("%d", &T[i]);
   }
   for(int i=0; i<Q; i++){
      scanf("%d %d", &V[i], &S[i]);
   }
   for(int i=0; i<N; i++){
      D[i] = C[i] - T[i];
   }
   sort(D, D+N);
   for(int i=0; i<Q; i++){
      int s = 0;
      int e = N-1;
      int ans = N;
      while(s <= e){
         int mid = (s+e)/2;
         if(D[mid] <= S[i]){
            s = mid + 1;
         }
         else{
            ans = mid;
            e = mid - 1;
         }
      }
      if(N-ans >= V[i]){
         printf("YES\n");
      }
      else{
         printf("NO\n");
      }

   }
   return 0;
}
