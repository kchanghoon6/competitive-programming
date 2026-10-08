#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll dp[200][200];
pll A[200];
ll n;

ll f(ll s, ll e){
   if(dp[s][e] != -1) return dp[s][e];
   dp[s][e] = 0;
   for(ll i=1; i<=n; i++){
      ll l = A[i].ff;
      ll r = A[i].ss;
      if(l < s || r > e)   continue;
      dp[s][e] = max(dp[s][e], f(s, l-1)+f(l+1, r-1)+f(r+1, e)+1);
   }
   return dp[s][e];
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   memset(dp, -1, sizeof(dp));
   for(ll i=1; i<=n; i++){
      ll a, b;
      cin >> a >> b;
      A[i] = {min(a, b), max(a, b)};
   }
   cout << f(1, 100) << "\n";

   return 0;
}
