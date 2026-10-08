#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll A[100];
ll B[100];
ll N;
int main(){
   scanf("%lld", &N);
   for(int i=0; i<N; i++){
      scanf("%lld", &A[i]);
   }
   for(int i=0; i<N; i++){
      scanf("%lld", &B[i]);
   }
   sort(A, A+N);
   sort(B, B+N);

   ll result = 1;
   for(ll i=0; i<N; i++){
      ll s=0, e=N-1;
      ll ans = -1;
      while(s<=e){
         ll mid = (s+e)/2;
         if(B[i] >= A[mid]){
            ans = mid;
            s = mid+1;
         }
         else{
            e = mid-1;
         }
      }
      result *= (ans+1-i);
   }
   printf("%lld\n", result);
}
