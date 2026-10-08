#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
ll A[6000];
ll B[6000];
ll L[12000];
ll R[12000];
ll D[12000];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n >> m;
   for(ll i=0; i<n; i++){
      ll a, b;
      cin >> a >> b;
      A[a]++;  B[b]++;
   }
   for(ll i=0; i<=m; i++){
      for(ll j=0; j<=m; j++){
         L[i+j] += A[i]*A[j];
         R[i+j] += B[i]*B[j];
      }
   }
   for(ll i=0; i<=2*m; i++){
      D[i] += L[i];
      D[i+1] -= R[i];
   }
   ll ans = 0;
   for(ll k=0; k<=2*m; k++){
      ans += D[k];
      cout << ans << "\n";
   }


   return 0;
}
