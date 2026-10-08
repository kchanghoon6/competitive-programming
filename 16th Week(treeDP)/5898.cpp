#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K;
vector<ll> G[100010];
ll C[100010];
ll up[100010][25];
ll down[100010][25];


void make_tree(ll node, ll par){
   down[node][0] = C[node];
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      for(ll k=1; k<=20; k++){
         down[node][k] += down[i][k-1];
      }
   }
}
void UP(ll node, ll par){
   up[node][0] = 0;
   for(auto i : G[node]){
      if(i == par)   continue;
      for(ll k=1; k<=K; k++){
         up[i][k] = (up[node][k-1] + down[node][k-1]);
         if(k >= 2)  up[i][k] -= down[i][k-2];
      }
      UP(i, node);
   }
}

int main(){
   scanf("%lld %lld", &N, &K);
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }
   for(ll i=1; i<=N; i++){
      scanf("%lld", &C[i]);
   }
   make_tree(1, 0);
   UP(1, 0);
   for(ll i=1; i<=N; i++){
      ll ans = 0;
      for(ll k=1; k<=K; k++){
         ans += (down[i][k] + up[i][k]);
      }
      printf("%lld\n", ans+C[i]);
   }

   return 0;
}
