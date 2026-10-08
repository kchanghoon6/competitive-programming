#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[30][300000];
ll m, q;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> m;
   for(ll i=1; i<=m; i++){
      cin >> A[0][i];
   }
   for(ll k=1; k<30; k++){
      for(ll i=1; i<=m; i++){
         A[k][i] = A[k-1][A[k-1][i]];
      }
   }
   cin >> q;
   while(q--){
      ll n, x;
      cin >> n >> x;
      for(ll k=0; k<30; k++){
         if(n & (1<<k)){
            x = A[k][x];
         }
      }
      cout << x << "\n";
   }
   return 0;
}
