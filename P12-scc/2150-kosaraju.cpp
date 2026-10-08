#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll v, e;
vector<ll> E1[20000];
vector<ll> E2[20000];
ll vt[20000];
vector<vector<ll>> A;
ll scc;
stack<ll> st;
vector<ll> B;

void dfs1(ll node){
   vt[node] = 1;
   for(auto i : E1[node]){
      if(!vt[i])  dfs1(i);
   }
   st.push(node);
}

void dfs2(ll k, ll node){
   vt[node] = 1;
   B.push_back(node);
   for(auto i : E2[node]){
      if(!vt[i])  dfs2(k, i);
   }
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> v >> e;
   for(ll i=0; i<e; i++){
      ll a, b;
      cin >> a >> b;
      E1[a].push_back(b);
      E2[b].push_back(a);
   }
   for(ll i=1; i<=v; i++){
      if(!vt[i])  dfs1(i);
   }
   fill(vt+1, vt+v+1, 0);
   while(!st.empty()){
      ll a = st.top();
      st.pop();
      if(!vt[a]){
         B.clear();
         dfs2(scc++, a);
         sort(B.begin(), B.end());
         A.push_back(B);
      }
   }
   cout << scc << "\n";
   sort(A.begin(), A.end());
   for(ll i=0; i<scc; i++){
      for(auto j : A[i]){
         cout << j << " ";
      }
      cout << "-1\n";
   }


   return 0;
}
