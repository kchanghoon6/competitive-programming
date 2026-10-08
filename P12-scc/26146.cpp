#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n, m, ans, scc;
ll vt[300000];
vector<ll> E1[300000];
vector<ll> E2[300000];
stack<ll> st;

void dfs1(ll node){
   vt[node] = 1;
   for(auto i : E1[node]){
      if(!vt[i])  dfs1(i);
   }
   st.push(node);
}
void dfs2(ll k, ll node){
   vt[node] = 1;
   for(auto i : E2[node]){
      if(!vt[i])  dfs2(k, i);
   }
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n >> m;
   for(ll i=0; i<m; i++){
      ll a, b;
      cin >> a >> b;
      E1[a].push_back(b);
      E2[b].push_back(a);
   }
   for(ll i=1; i<=n; i++){
      if(!vt[i])  dfs1(i);
   }
   fill(vt+1, vt+n+1, 0);
   while(!st.empty()){
      ll a = st.top();
      st.pop();
      if(!vt[a]){
         dfs2(scc++, a);
      }
   }
   if(scc == 1)   cout << "Yes\n";
   else  cout << "No\n";
   return 0;
}
