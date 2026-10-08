#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int A[2000];
int B[100];
int main(){
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   sort(A, A+N);
   for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
         int xy = A[j] - A[i];
         int s = j+1;
         int e = N-1;
         int ans = N;
         while(s <= e){
            int mid = (s+e)/2;
            int yz = A[mid]-A[j];
            if(yz >= xy){
               ans = mid;
               e = mid - 1;
            }
            else{
               s = mid + 1;
            }
         }
         s = j+1;
         e = N-1;
         int ans2 = j;
         while(s <= e){
            int mid = (s+e)/2;
            int yz = A[mid]-A[j];
            if(yz <= 2*xy){
               ans2 = mid;
               s = mid + 1;
            }
            else{
               e = mid - 1;
            }
         }
         if(ans <= ans2)
            cnt += ans2 - ans + 1;
      }
   }
   printf("%d\n", cnt);
   return 0;
}
