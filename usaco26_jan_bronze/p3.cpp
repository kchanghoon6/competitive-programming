#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll n, k, q;
ll A[800][800];
ll G[800][800];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> n >> k;
   cin >> q;

   ll maxi = 0;
   while(q--){
      ll r, c, v;
      cin >> r >> c >> v;
      ll d = v-G[r][c];
      G[r][c] = v;
      for(ll i=max(1LL, r-k+1); i<=min(r, n-k+1); i++){
         for(ll j=max(1LL, c-k+1); j<=min(c, n-k+1); j++){
            A[i][j] += d;
            maxi = max(maxi, A[i][j]);
         }
      }
      cout << maxi << "\n";
   }



   return 0;
}
