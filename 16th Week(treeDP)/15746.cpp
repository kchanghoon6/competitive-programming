#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
vector<ll> G[200000];
ll file[200000];
ll len[200000];
ll C[200000];
ll dp[200000];
ll num;

void make_tree(ll node, ll par){
   if(file[node]) C[node] = 1;
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      C[node] += C[i];
      if(file[i]) dp[node] += len[i];
      else  dp[node] += dp[i] + C[i]*(len[i]+1);
   }
}
void min_dist_sum(ll node, ll par){
   for(auto i : G[node]){
      if(i == par)   continue;
      if(file[i]) continue;
      dp[i] = dp[node]-C[i]*(len[i]+1)+(num-C[i]) *3;
      min_dist_sum(i, node);
   }
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> N;
   for(ll i=1; i<=N; i++){
      string name;
      ll m;
      cin >> name >> m;
      len[i] = name.size();
      if(m == 0)  file[i] = 1;
      for(ll j=0; j<m; j++){
         ll a;
         cin >> a;
         G[i].push_back(a);
      }
   }
   make_tree(1, 0);
   num = C[1];
   min_dist_sum(1, 0);
   ll result = 1e15;
   for(ll i=1; i<=N; i++){
      if(file[i]) continue;
      result = min(result, dp[i]);
   }
   cout << result << "\n";
   return 0;
}
