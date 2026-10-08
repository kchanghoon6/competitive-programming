#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll N, H;
ll dp[1100000];   // (가장 힘 얼마 안 남은 거 몇, 현재 높이)
ll w[1100000];
ll h[1100000];
vector<pair<pll, ll>> A;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> N >> H;
   for(ll i=0; i<N; i++){
      ll a, b, c;
      cin >> a >> b >> c;
      A.push_back({{a, b}, c}); // height, weight, strength
   }

   for(ll mk=0; mk<(1<<N); mk++){
      dp[mk] = -1;
      for(ll i=0; i<N; i++){
         if(mk & (1 << i)){
            w[mk] += A[i].ff.ss;
            h[mk] += A[i].ff.ff;
         }
      }
   }
   dp[0] = 1e10;
   for(ll mk=0; mk<(1<<N); mk++){
      for(ll u=0; u<N; u++){
         if((mk & (1 << u))) continue;
         if(A[u].ss >= w[mk]){
            dp[mk | (1<<u)] = max(dp[mk | (1<<u)], min(dp[mk], A[u].ss-w[mk]));
         }
      }
   }
   ll maxi = -1;
   for(ll mk=1; mk<(1<<N); mk++){
      for(ll i=0; i<N; i++){
         if(H <= h[mk]){
            maxi = max(dp[mk], maxi);
         }
      }
   }
   if(maxi == -1){
      cout << "Mark is too tall" << "\n";
   }
   else{
      cout << maxi << "\n";
   }
   return 0;
}
