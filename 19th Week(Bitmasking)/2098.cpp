#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll dp[80000][20];
ll A[30][30];
ll N;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   for(ll i=0; i<N; i++){
      for(ll j=0; j<N; j++){
         cin >> A[i][j];
      }
   }
   for(ll i=0; i<(1<<N); i++){
      for(ll j=0; j<N; j++){
         dp[i][j] = 1e15;
      }
   }
   dp[1][0] = 0;

   for(ll k=1; k<(1<<N); k++){
      for(ll i=0; i<N; i++){
         if(!(k & (1<<i))) continue;
         if(dp[k][i] > 1e14)  continue;
         for(ll j=0; j<N; j++){
            if(k & (1 << j))  continue;
            if(A[i][j] == 0) continue;
            ll u = k | (1 << j);
            dp[u][j] = min(dp[k][i]+A[i][j], dp[u][j]);
         }
      }
   }
   ll mini = 1e15;
   for(ll i=1; i<N; i++){
      if(A[i][0] == 0)  continue;
      mini = min(mini, dp[(1<<N)-1][i]+A[i][0]);
   }
   cout << mini << "\n";

   return 0;
}
