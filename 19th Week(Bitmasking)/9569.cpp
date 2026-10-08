#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll K, N;
ll C[30];
ll A[200000];
ll P[200000];
ll sum[200000];
ll dp[200000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> K >> N;

   for(ll i=0; i<K; i++){
      cin >> C[i];
   }
   for(ll i=0; i<N; i++){
      cin >> P[i];
   }
   for(ll i=1; i<=N; i++){
      sum[i] = sum[i-1] + P[i-1];
   }
   for(ll mk=0; mk<(1<<K); mk++){
      for(ll i=0; i<K; i++){
         if(!(mk & (1<<i)))   continue;
         ll prev = mk ^ (1<<i);  // dp[prev] : 현재부터 고려해야하는 purchase
         ll idx = upper_bound(sum, sum+N+1, C[i]+sum[dp[prev]])-sum-1;
         dp[mk] = max(dp[mk], idx);
      }
   }
   for(ll mk=0; mk<(1<<K); mk++){
      A[mk] = 0;
      for(ll i=0; i<K; i++){
         if(mk & (1<<i)){
            A[mk] += C[i];
         }
      }
   }
   ll total = 0;
   for(ll i=0; i<K; i++) total += C[i];
   ll maxi = -1;
   for(ll mk=0; mk<(1<<K); mk++){
      if(dp[mk] == N){
         maxi = max(maxi, total-A[mk]);
      }
   }
   cout << maxi << "\n";

   return 0;
}
