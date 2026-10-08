#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> G[200000];
ll A[200000];
ll vt[200000];
ll fin[200000];
ll indegree[200000];
ll scc, ans, t, idx;
stack<ll> st;

ll dfs(ll node){
   vt[node] = ++idx;
   st.push(node);
   ll lo = vt[node];

   for(auto i : G[node]){
      if(!vt[i])  lo = min(lo, dfs(i));
      if(!fin[i]) lo = min(lo, vt[i]);
   }
   if(lo == vt[node]){
      while(!st.empty()){
         ll a = st.top();
         st.pop();
         A[a] = scc+1;
         fin[a] = node;
         if(a == node){
            break;
         }
      }
      scc++;
   }
   return lo;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> t;
   while(t--){
      ll n, m;
      cin >> n >> m;
      for(ll i=1; i<=n; i++){
         G[i].clear();
         vt[i] = 0;
         fin[i] = 0;
         A[i] = 0;
         indegree[i] = 0;
      }
      scc = idx = ans = 0;
      while(!st.empty()) st.pop();
      for(ll i=0; i<m; i++){
         ll a, b;
         cin >> a >> b;
         G[a].push_back(b);
      }
      for(ll i=1; i<=n; i++){
         if(!vt[i])  dfs(i);
      }
      for(ll i=1; i<=n; i++){
         for(auto j : G[i]){
            if(A[i] != A[j]){
               indegree[A[j]]++;
            }
         }
      }
      for(ll i=1; i<=scc; i++){
         if(indegree[i]==0) ans++;
      }
      cout << ans << "\n";
   }
   return 0;
}
