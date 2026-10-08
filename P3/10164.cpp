#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M, K;
ll ans;

ll comb(ll n, ll r){
   ll ret = 1;
   for(ll i=1; i<=r; i++){
      ret *= (n-i+1);
   }
   for(ll i=1; i<=r; i++){
      ret /= i;
   }
   return ret;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> M >> K;

   if(K != 0){
      ll x = (K-1)/M + 1;
      ll y = (K-1)%M + 1;
      cout << comb(x+y-2, x-1) * comb(N+M-x-y, N-x) << "\n";
   }
   else{
      cout << comb(N+M-2, N-1) << "\n";
   }
   return 0;
}
