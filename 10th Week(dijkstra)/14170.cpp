#include <bits/stdc++.h>
using namespace std;

int N, Q;
int L[200000];
int A[200000];
int B[200000];

int main(){
   scanf("%d %d", &N, &Q);
   int maxi = 0;
   for(int i=0; i<N; i++){
      scanf("%d", &L[i]);
      maxi = max(maxi, L[i]);
   }
   sort(L, L+N);
   for(int i=0; i<Q; i++){
      scanf("%d %d", &A[i], &B[i]);
   }
   for(int i=0; i<Q; i++){
      if(A[i] > maxi){
         printf("0\n");
         continue;
      }
      int s = 0;
      int e = N-1;
      int ans = 0;
      while(s <= e){
         int mid = (s+e)/2;
         if(L[mid] >= A[i]){
            ans = mid;
            e = mid - 1;
         }
         else if(L[mid] < A[i]){
            s = mid + 1;
         }
      }
      int st_idx = ans;

      s = 0;
      e = N-1;
      ans = 0;
      while(s <= e){
         int mid = (s+e)/2;
         if(L[mid] <= B[i]){
            ans = mid;
            s = mid + 1;
         }
         else if(L[mid] > B[i]){
            e = mid - 1;
         }
      }
      int end_idx = ans;
      printf("%d\n", end_idx - st_idx + 1);
   }
   return 0;
}
