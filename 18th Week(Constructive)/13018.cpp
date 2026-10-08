#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, K;
ll A[200000];
int main(){
   scanf("%lld %lld", &N, &K);
   for(ll i=1; i<=N; i++){
      A[i] = i;
   }
   if(K > N-1){
      printf("Impossible\n");
      return 0;
   }
   else{
      ll diff = (N-1)-K;
      ll cnt = 0;
      if(diff%2){
         for(ll i=1; i<=N-1 && cnt < diff; i+=2){
            swap(A[i], A[i+1]);
            cnt+=2;
         }
      }
      else{
         for(ll i=2; i<=N-1 && cnt < diff; i+=2){
            swap(A[i], A[i+1]);
            cnt+=2;
         }
      }
   }
   for(ll i=1; i<=N; i++){
      printf("%lld ", A[i]);
   }
   printf("\n");
   return 0;
}
