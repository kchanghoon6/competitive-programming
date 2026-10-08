#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;
vector<ll> A[100000];
ll P[100000];
ll D[100000];

void make_tree(ll node, ll par){
   P[node] = par;
   D[node] = D[par]+1;
   for(auto i : A[node]){
      if(i == par)   continue;
      make_tree(i, node);
   }
}

ll LCA(ll u, ll v){
   if(D[u] < D[v]){
      swap(u, v);
   }  // u > v
   while(D[u] != D[v]){
      u = P[u];
   } // u == v;
   while(u != v){
      u = P[u];
      v = P[v];
   }
   return u;
}
int main(){
   scanf("%lld", &N);
   for(ll i=0; i<N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      A[a].push_back(b);
      A[b].push_back(a);
   }
   make_tree(1, 0);
   scanf("%lld", &M);
   for(ll i=0; i<M; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      printf("%lld\n", LCA(a, b));
   }


   return 0;
}
