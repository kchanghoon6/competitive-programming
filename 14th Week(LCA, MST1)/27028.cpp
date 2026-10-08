#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, M, K;
vector<pll> A[50000];
ll D[50000];
ll dist[50000];
ll P[50000][30];

void make_tree(ll node, ll len, ll par){
   P[node][0] = par;
   D[node] = D[par] + 1;
   dist[node] = dist[par] + len;
   for(auto i : A[node]){
      if(i.ff == par)   continue;
      make_tree(i.ff, i.ss, node);
   }
}

ll lca(ll u, ll v){
   if(D[u] < D[v])   swap(u, v);
   for(ll i=28; i>=0; i--){
      if((1LL << i) <= D[u]-D[v]){
         u = P[u][i];
      }
   }
   if(u == v)  return u;
   for(ll i=28; i>=0; i--){
      if(P[u][i] != P[v][i]){
         u = P[u][i];
         v = P[v][i];
      }
   }
   return P[u][0];
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   cin >> N >> M;
   for(ll i=0; i<M; i++){
      ll a, b, c;
      char d;
      cin >> a >> b >> c >> d;
      A[a].push_back({b, c});
      A[b].push_back({a, c});
   }
   make_tree(1, 0, 1);
   for(ll k=1; k<=28; k++){
      for(ll x=1; x<=N; x++){
         P[x][k] = P[P[x][k-1]][k-1];
      }
   }
   cin >> K;
   for(ll i=0; i<K; i++){
      ll a, b;
      cin >> a >> b;
      ll anc = lca(a, b);
      cout << dist[a]+dist[b]-2*dist[anc] << "\n";
   }
   return 0;
}
