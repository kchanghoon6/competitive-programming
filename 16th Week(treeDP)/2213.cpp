#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N;
ll W[20000];
vector<ll> G[20000];
ll dp[20000][5];
vector<ll> A;

void make_tree(ll node, ll par){
   dp[node][0] = 0;
   dp[node][1] = W[node];
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      dp[node][0] += max(dp[i][0], dp[i][1]);
      dp[node][1] += dp[i][0];
   }
}
void tree_check(ll node, ll par, bool choice){
   if(choice)  A.push_back(node);
   for(auto i : G[node]){
      if(i == par)   continue;
      if(choice)  tree_check(i, node, 0);
      else{
         if(dp[i][1] > dp[i][0]) tree_check(i, node, 1);
         else  tree_check(i, node, 0);
      }
   }
}

int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &W[i]);
   }
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   make_tree(1, 0);
   ll maxi = 0;
   ll choice = 0;
   if(dp[1][1] > dp[1][0]){
      maxi = dp[1][1];
      choice = 1;
   }
   else{
      maxi = dp[1][0];
   }
   tree_check(1, 1, choice);
   printf("%lld\n", maxi);
   sort(A.begin(), A.end());
   for(auto i : A){
      printf("%lld ", i);
   }
   printf("\n");

   return 0;
}
