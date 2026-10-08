#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T;
int main(){
   scanf("%lld", &T);
   while(T--){
      ll a, b, c, d;
      scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
      ll cnt = 0;
      while(a!=c || b!=d){
         if(a==c && b==d)  break;
         if(c < a || d < b){
            cnt = -1;
            break;
         }
         if(c > d){
            ll times = (c-a)/d;
            if(times == 0) times = 1;
            cnt += times;
            c -= d*times;
         }
         else{
            ll times = (d-b)/c;
            if(times == 0) times = 1;
            cnt += times;
            d -= c*times;
         }
      }
      printf("%lld\n", cnt);
   }

   return 0;
}
