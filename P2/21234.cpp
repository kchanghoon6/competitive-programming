#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll G[600][600];
ll L[600][600];
ll U[600][600];

ll f(ll x){
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         if(G[i][j] < x){
            L[i][j] = 0;
            U[i][j] = 0;
         }
         else{
            L[i][j] = L[i][j-1] + 1;
            U[i][j] = U[i-1][j] + 1;
         }
      }
   }
   ll ans = 0;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         ll W = L[i][j];
         for(ll k=i; k>=i-U[i][j]+1; k--){
            W = min(W, L[k][j]);
            ans += W;
         }
      }
   }
   return ans;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         cin >> G[i][j];
      }
   }
   cout << f(100)-f(101) << "\n";

   return 0;
}
