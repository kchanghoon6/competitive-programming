#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll A[200000];  // i번째에 A[i]에 포션 생김
vector<ll> G[200000];
ll dp[200000];
ll pot[200000];
ll leaf[200000];
ll ans;

ll leaves(ll node, ll par){
   ll sum = 0;
   ll c = 0;
   for(auto i : G[node]){
      if(i == par)   continue;
      c++;
      sum += leaves(i, node);
   }
   if(c == 0)  sum = 1;
   leaf[node] = sum;
   return sum;
}
void make_tree(ll node, ll par){
   dp[node] = 0;
   ll child = 0;
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      child++;
      dp[node] += dp[i];
   }
   if(child == 0) dp[node]++;
   ans += min(pot[node], dp[node]);
   dp[node] -= min(pot[node], dp[node]);
}


int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &A[i]);
   }
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   leaves(1, 0);
   ll t = leaf[1];
   for(ll i=1; i<=t; i++){
      pot[A[i]]++;
   }
   make_tree(1, 0);
   printf("%lld\n", ans);
   return 0;
}
