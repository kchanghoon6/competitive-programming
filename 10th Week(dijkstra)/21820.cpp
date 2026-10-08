#include <bits/stdc++.h>
using namespace std;
int N, L;
int A[500000];
int main(){
   scanf("%d %d", &N, &L);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   sort(A, A+N);

   int s = 0;
   int e = N-1;
   int mid;
   int h = 0;
   while(s <= e){
      mid = (s+e)/2;
      if(A[N-1-mid] >= mid+1){
         h = mid + 1;
         s = mid + 1;
      }
      else{
         e = mid - 1;
      }
   }

   int idx_h = 0;
   int idx_h1 = 0;
   for(int i=0; i<N; i++){
      if(A[i] >= h+1){
         idx_h1++;
      }
   }
   for(int i=0; i<N; i++){
      if(A[i] == h){
         idx_h++;
      }
   }

   if(h+1 - idx_h1 <= min(idx_h, L)){
      printf("%d\n", h+1);
   }
   else{
      printf("%d\n", h);
   }
   return 0;
}
