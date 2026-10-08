#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll H[300000];
ll n, b, ans;
vector<ll> G[300000];
ll sub_sz[300000];
ll sub_sum[300000];
ll vt[300000];
ll E[300000];
vector<pll> V[300000];
vector<pair<pll, ll>> out;

void dfs(ll node){
   vt[node] = 1;
   sub_sz[node] = 1;
   sub_sum[node] = H[node];
   for(auto i : G[node]){
      if(vt[i])   continue;
      dfs(i);
      E[i] = sub_sum[i]-sub_sz[i]*b;
      V[node].push_back({E[i], i});
      sub_sz[node] += sub_sz[i];
      sub_sum[node] += sub_sum[i];
   }
}
void dfs2(ll node){
   vt[node] = 1;
   for(auto i : V[node]){
      if(vt[i.ss]) continue;
      if(E[i.ss] > 0){
         dfs2(i.ss);
         out.push_back({{i.ss, node}, E[i.ss]});
      }
      if(E[i.ss] < 0){
         out.push_back({{node, i.ss}, -E[i.ss]});
         dfs2(i.ss);
      }
      if(E[i.ss] == 0){
         dfs2(i.ss);
      }
   }
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   for(ll i=1; i<=n; i++){
      cin >> H[i];
      b += H[i];
   }
   b = b/n;
   for(ll i=0; i<n-1; i++){
      ll u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }
   for(ll i=1; i<=n; i++){
      if(!vt[i])  dfs(i);
   }
   for(ll i=1; i<=n; i++){
      vt[i] = 0;
      sort(V[i].rbegin(), V[i].rend());
   }
   for(ll i=1; i<=n; i++){
      if(!vt[i])  dfs2(i);
   }
   cout << out.size() << "\n";
   for(auto i : out){
      cout << i.ff.ff << " " << i.ff.ss << " " << i.ss << "\n";
   }


   return 0;
}
