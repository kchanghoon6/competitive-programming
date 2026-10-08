#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


pll dp[200100][10];        // {최대 bessie 개수, 제거 비용}
ll A[200100];              // 제거 비용
string bes = "bessie";
string str;

pll isBetter(pll x, pll y){
   if(x.ff == y.ff){
      return (x.ss < y.ss) ? x : y;
   }
   return (x.ff > y.ff) ? x : y;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> str;
   ll len = str.size();
   for(ll i=0; i<len; i++){
      cin >> A[i];
   }
   for(ll i=0; i<len; i++){
      for(ll k=0; k<6; k++){
         dp[i][k] = {0, 1e15};
      }
   }
   dp[0][0] = {0, 0};
   for(ll i=0; i<len; i++){
      for(ll k=0; k<6; k++){
         if(i != 0){
            if(str[i] == bes[k] && k == 5){
               pll p = dp[i-1][k-1];
               p.ff++;
               dp[i][k] = isBetter(p, dp[i][k]);
            }
            else if(str[i] == bes[k] && k > 0){
               dp[i][k] = isBetter(dp[i-1][k-1], {dp[i-1][k].ff, dp[i-1][k].ss + A[i]});
               // dp[i][k].ff = dp[i-1][k-1].ff;
               // dp[i][k].ss = min(dp[i][k].ss, dp[i-1][k-1].ss);
            }
            else  dp[i][k].ss = min(dp[i][k].ss, dp[i-1][k].ss + A[i]);
         }
         else{
            if(str[i] != bes[k]) dp[i][k].ss = A[i];
            else dp[i][k].ss = 0;
         }
      }
   }
   ll maxi = 0;
   ll cost = 1e15;
   for(ll i=0; i<6; i++){
      if(maxi <= dp[len-1][i].ff){
         maxi = dp[len-1][i].ff;
         cost = min(cost, dp[len-1][i].ss);
      }
   }
   for(ll i=0; i<len; i++){
      for(ll k=0; k<6; k++){
         cout << dp[i][k].ss << " ";
      }
      cout << "\n";
   }

   cout << maxi << "\n" << cost << "\n";
   return 0;
}
