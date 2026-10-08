#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t;
ll C[200];
ll M[200];
ll T[200];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> t;
   while(t--){
      ll n, tc, tm;
      cin >> n >> tc >> tm;
      for(ll i=0; i<n; i++)   cin >> C[i] >> M[i] >> T[i];
      ll s=2, e = tc+tm;
      while(s < e){
         ll u = (s+e+1)/2;
         ll low = max(1LL, u-tm), high = min(u-1, tc);
         ll flag = 1;
         for(ll i=0; i<n; i++){
            ll t1 = T[i]-u*M[i];
            ll t2 = C[i]-M[i];

            if(t2 > 0){
               if(t1 < 0){
                  flag = 0;
                  break;
               }
               high = min(high, t1 / t2);
            }
            else if(t2 < 0){
               ll bd;
               if(t1 <= 0)  bd = (t1+t2+1)/t2;
               else  bd = t1/t2;
               low = max(low, bd);
            }
            else{
               if(t1 < 0){
                  flag = 0;
                  break;
               }
            }
            if(low > high){
               flag = 0;
               break;
            }
         }
         if(flag && low <= high) s = u;
         else  e = u-1;
      }
      cout << tc+tm-s << "\n";
   }

   return 0;
}
