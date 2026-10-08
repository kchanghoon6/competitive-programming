#include <bits/stdc++.h>
#define ff first
#define ss second
#define pii pair<int, int>

using namespace std;
int A[2000000];       // xi, gi

int main(){
   int N, K;
   scanf("%d %d", &N, &K);

   int max_idx = 0;
   for(int i=0; i<N; i++){
      int idx, a;
      scanf("%d %d", &a, &idx);
      max_idx = max(max_idx, idx);
      A[idx] = a;
   }
   int s = 0, e = 0, sum = 0;
   int maxi = 0;
   while(e < max_idx){
      while(e - s < 2*K && e < max_idx){
         sum += A[e];
         e++;
      }
      if(e <= max_idx){
         sum += A[e];
         maxi = max(maxi, sum);
      }
      sum -= A[s];
      s++;
      e++;
   }
   printf("%d\n", maxi);
   return 0;
}
