#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll K, N;
ll X[2000];
int main(){
   scanf("%lld %lld", &K, &N);
   for(ll i=0; i<N; i++){
      scanf("%lld", &X[i]);
   }
   for(ll i=0; i<N; i++){
      ll T = (X[i]+1)*X[i]/2;
      ll ans = 0;
      ll s = 1, e=X[i];
      while(s <= e){
         ll mid = (s+e)/2;
         if((mid+1)*mid/2 >= K){
            e = mid-1;
            ans = mid;
         }
         else  s = mid+1;
      }
      if(T >= K){
         printf("%lld\n", ans);
      }
      else{
         ll x = X[i];
         ll p = x*(x-1)/2;
         ll s = x, e = 100000, ans=e;
         while(s <= e){
            ll mid = (s+e)/2;
            if(mid*mid - p >= K){
               ans = mid;
               e = mid-1;
            }
            else  s = mid+1;
         }
         if(ans*(ans-1)-p >= K){
            printf("%lld\n", 2*ans-x-1);
         }
         else{
            printf("%lld\n", 2*ans-x);
         }
      }
   }
   return 0;
}
