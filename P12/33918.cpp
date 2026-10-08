#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll dp[300][30000];
ll B[30000];
ll n, m, c, d;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> n >> m >> c >> d;

   for(ll i=0; i<=n-1; i++){
      cin >> B[i];
   }

   for(ll t=0; t<=n-1; t++){
      for(ll k=1; k<=m; k++){
         dp[t][k] = m-(abs(B[t]-k));
      }
   }

   priority_queue<pll> pq;
   for(ll t=0; t<=n-1; t++){
      for(ll i=1; i<=c; i++){
         while(!pq.empty())   pq.pop();
         ll cc = i;
         for(cc=i; cc<=i+d && cc<=m; cc+=c){
            pq.push({dp[t][cc], cc});
         }

         for(cc=i; cc<=m; cc+=c){
            if(cc+d <= m)  pq.push({dp[t][cc+d], cc+d});
            while(!pq.empty() && pq.top().ss < cc-d){
               pq.pop();
            }
            dp[t+1][cc] += pq.top().ff;
         }
      }
   }
   ll ans = 0;
   for(ll i=1; i <= m; i++){
      ans = max(ans, dp[n-1][i]);
   }
   cout << ans << "\n";
   return 0;
}
