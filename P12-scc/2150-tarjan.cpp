#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll v, e;
vector<ll> G[20000];
ll vt[20000];
ll fin[20000];
vector<vector<ll>> A;
ll scc;
stack<ll> st;
ll idx;

ll dfs(ll node){
   vt[node] = ++idx;
   st.push(node);
   ll lo = vt[node];

   for(auto i : G[node]){
      if(!vt[i])  lo = min(lo, dfs(i));
      if(!fin[i]) lo = min(lo, vt[i]);
   }
   if(lo == vt[node]){
      vector<ll> B;
      while(!st.empty()){
         ll a = st.top();
         st.pop();
         B.push_back(a);
         fin[a] = node;
         if(a == node){
            break;
         }
      }
      sort(B.begin(), B.end());
      A.push_back(B);
      scc++;
   }
   return lo;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> v >> e;
   for(ll i=0; i<e; i++){
      ll a, b;
      cin >> a >> b;
      G[a].push_back(b);
   }
   for(ll i=1; i<=v; i++){
      if(!vt[i])  dfs(i);
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
