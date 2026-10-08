#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K;
ll A[200];
ll dp[100000][30];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> K;
   for(ll i=0; i<N; i++){
      cin >> A[i];
      dp[1<<i][i] = 1;
   }
   for(ll mk=1; mk<(1<<N); mk++){
      for(ll u=0; u<N; u++){
         if(!(mk & (1 << u))) continue;
         for(ll v=0; v<N; v++){
            if(u == v)  continue;
            if(abs(A[u]-A[v]) <= K) continue;
            if(mk & (1<<v)) continue;
            dp[mk | (1<<v)][v] += dp[mk][u];
         }
      }
   }
   ll ans = 0;
   for(ll i=0; i<N; i++){
      ans += dp[(1<<N)-1][i];
   }
   cout << ans << "\n";


   return 0;
}
