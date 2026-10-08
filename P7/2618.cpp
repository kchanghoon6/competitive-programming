#include <bits/stdc++.h>
#define ll long long

#define ff first
#define ss second
using namespace std;


ll N, W;
ll dp[1010][1010];
pll A[1010];

ll dfs(ll x1, ll x2, ll idx){
   if(dp[x1][x2]){
      return dp[x1][x2];
   }
   ll c1 = dfs(idx, x2, idx+1);
   ll c2 = dfs(x1, idx, idx+1);
   ll d1 = abs(A[idx].ff-A[x1].ff) + abs(A[idx].ss-A[x1].ss);
   ll d2 = abs(A[idx].ff-A[x2].ff) + abs(A[idx].ss-A[x2].ss);
   if(c1+d1 < c2+d2){
      dp[x1][x2] = c1+d1;
   }
   else{
      dp[x1][x2] = c2+d2;
   }

}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> W;
   dp[0][0] = 0;
   A[0] = {1, 1};
   A[1] = {N, N};
   for(ll i=2; i<=W+1; i++){
      cin >> A[i].ff >> A[i].ss;
   }

   return 0;
}
