#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N, M, C;
ll A[200000];

bool f(ll t){
   ll bus = 0;
   ll i = 0;
   while(i < N){
      if(bus+1 > M)  return false;
      else  bus++;
      ll depart = A[i] + t;
      ll cnt = 0;

      while(i < N && cnt < C && A[i] <= depart){
         cnt++;
         i++;
      }
   }
   return true;
}


int main(){
   scanf("%lld %lld %lld", &N, &M, &C);
   for(int i=0; i<N; i++){
      scanf("%lld", &A[i]);
   }
   sort(A, A+N);
   ll s = 0;
   ll e = A[N-1] - A[0];
   ll ans;
   while(s <= e){
      ll mid = (s+e)/2;
      if(f(mid)){
         ans = mid;
         e = mid - 1;
      }
      else{
         s = mid + 1;
      }
   }
   printf("%lld\n", ans);
}
