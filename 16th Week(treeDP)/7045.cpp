#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
vector<ll> G[20000];
vector<ll> A;
ll child[20000];

void make_tree(ll node, ll par){
   child[node] = 1;
   for(auto i : G[node]){
      if(i == par)   continue;
      make_tree(i, node);
      child[node] += child[i];
   }
}

int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
   }

   make_tree(1, 0);
   for(ll i=1; i<=N; i++){
      ll maxi = N-child[i];
      for(auto j : G[i]){
         if(child[j] < child[i]) maxi = max(maxi, child[j]);
      }
      if(maxi <= N/2)   printf("%lld\n", i);
   }

   return 0;
}
