#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll n, m, s, p;
vector<ll> G[600000];
vector<ll> H[600000];
stack<ll> st;
ll A[600000];
ll B[600000];
pll C[600000];
ll D[600000];
ll dp[600000];
ll R[600000];
ll vt[600000];
ll fin[600000];
ll idx, scc;

ll dfs(ll node){
   vt[node] = ++idx;
   st.push(node);
   ll lo = vt[node];
   for(auto i : G[node]){
      if(!vt[i])  lo = min(lo, dfs(i));
      if(!fin[i]) lo = min(lo, vt[i]);
   }
   if(lo == vt[node]){
      scc++;
      ll sum = 0;
      while(!st.empty()){
         ll a = st.top();
         st.pop();
         sum += A[a];
         if(R[a]) D[scc] = 1;
         fin[a] = scc;
         if(a == node)  break;
      }
      B[scc] = sum;
   }
   return lo;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n >> m;
   for(ll i=0; i<m; i++){
      ll a, b;
      cin >> a >> b;
      G[a].push_back(b);
      C[i] = {a, b};
   }
   for(ll i=1; i<=n; i++){
      cin >> A[i];
   }
   cin >> s >> p;
   for(ll i=1; i<=p; i++){
      ll a;
      cin >> a;
      R[a] = 1;
   }
   for(ll i=1; i<=n; i++){
      if(!vt[i])  dfs(i);
   }
   for(ll i=0; i<m; i++){
      ll u = C[i].ff;   ll v = C[i].ss;
      if(fin[u] != fin[v]){
         H[fin[u]].push_back(fin[v]);
      }
   }
   memset(dp, -1, sizeof(dp));
   dp[fin[s]] = B[fin[s]];
   for(ll i=scc; i>=1; i--){
      if(dp[i] == -1)   continue;
      for(auto j : H[i]){
         dp[j] = max(dp[j], dp[i]+B[j]);
      }
   }
   ll ans = 0;
   for(ll i=1; i<=scc; i++){
      if(D[i] && dp[i] != -1){
         ans = max(ans, dp[i]);
      }
   }
   cout << ans << "\n";

   return 0;
}
