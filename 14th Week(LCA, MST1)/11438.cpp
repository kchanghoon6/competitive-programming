#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, M;
vector<ll> A[200000];
ll D[200000];
ll P[200000][30];

void make_tree(ll node, ll par){
   P[node][0] = par;
   D[node] = D[par]+1;
   for(auto i : A[node]){
      if(i == par)   continue;
      make_tree(i, node);
   }
}

ll lca(ll u, ll v){
   if(D[u] < D[v])   swap(u, v);
   for(ll i=28; i>=0; i--){
      if((1LL<<i) <= D[u]-D[v]){
         u = P[u][i];
      }
   }
   if(u == v)  return u;
   for(ll i=28; i>=0; i--){
      if(P[v][i] != P[u][i]){
         u = P[u][i];
         v = P[v][i];
      }
   }
   return P[u][0];
}

int main(){
   scanf("%lld", &N);
   for(ll i=0; i<N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      A[a].push_back(b);
      A[b].push_back(a);
   }
   make_tree(1, 1);
   for(ll k=1; k<=28; k++){
      for(ll x=1; x<=N; x++){
         P[x][k] = P[P[x][k-1]][k-1];
      }
   }
   scanf("%lld", &M);
   for(ll i=0; i<M; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      printf("%lld\n", lca(a, b));

   }
   return 0;
}
