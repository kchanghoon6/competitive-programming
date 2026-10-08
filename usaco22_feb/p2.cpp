#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200000];
ll B[200000];
ll C[200000];
ll n;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   for(ll i=1; i<=n; i++){
      cin >> A[i];
   }
   for(ll i=1; i<=n; i++){
      cin >> B[i];
      C[B[i]] = i;
   }

   for(ll i=1; i<=n; i++){
      A[i] = C[A[i]];
   }
   ll ans = 0;
   ll maxi = 0;
   for(ll i=1; i<=n; i++){
      if(A[i] > maxi)   maxi = A[i];
      else  ans++;
   }
   cout << ans << "\n";

   return 0;
}
