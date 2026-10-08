#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N;

ll moo_count(ll ub){
   ll cnt5 = ub/5;
   ll cnt3 = ub/3;
   ll cnt15 = ub/15;
   ll result = cnt5 + cnt3 - cnt15;
   return result;
}

int main(){
   scanf("%lld", &N);
   ll s = 1;
   ll e = 1e18;
   ll ans;
   while(s <= e){
      ll mid = (s+e)/2;
      ll cnt = moo_count(mid);
      if(mid - cnt > N){
         e = mid - 1;
      }
      else if(mid - cnt < N){
         s = mid + 1;
      }
      else{
         ans = mid;
         e = mid - 1;
      }
   }
   printf("%lld\n", ans);
   return 0;
}
