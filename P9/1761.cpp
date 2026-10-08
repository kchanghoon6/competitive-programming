#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, M;
vector<pll> G[100000];
ll D[100000];
ll P[100000][30];
ll dist[100000];

void make_tree(ll node, ll par, ll d){
   P[node][0] = par;
   D[node] = D[par]+1;
   dist[node] = dist[par]+d;

   for(auto i : G[node]){
      if(i.ff == par)   continue;
      make_tree(i.ff, node, i.ss);
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
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N;
   for(ll i=1; i<N; i++){
      ll a, b, c;
      cin >> a >> b >> c;
      G[a].push_back({b, c});
      G[b].push_back({a, c});
   }
   make_tree(1, 1, 0);
   for(ll k=1; k<=28; k++){
      for(ll x=1; x<=N; x++){
         P[x][k] = P[P[x][k-1]][k-1];
      }
   }
   cin >> M;
   for(ll i=1; i<=M; i++){
      ll a, b;
      cin >> a >> b;
      ll anc = lca(a, b);

      cout << dist[a]+dist[b]-2*dist[anc] << "\n";
   }
   return 0;
}
