#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N, K, T;
int A[500000];
int B[500000];

int main(){
   scanf("%d %d %d", &N, &K, &T);
   for(int i=0; i<K; i++){
      int a;
      scanf("%d", &a);
      A[i] = a;
   }
   A[K] = N;
   for(int i=0; i<K; i++){
      int cycle = A[i+1]-A[i];
      for(int j=A[i]; j<A[i+1]; j++){
         int k = -T%cycle;
         int idx = (j-A[i]+k+cycle*2)%cycle+A[i];
         B[idx] = j;
      }
   }
   int ans[500000];
   for(int i=0; i<N; i++){
      ans[(i+T)%N] = B[i];
   }
   for(int i=0; i<N; i++){
      printf("%d ", ans[i]);
   }
   printf("\n");
   return 0;
}
