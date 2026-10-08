#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n, m;
ll vt[110000];
ll fin[110000];
vector<ll> A[110000];
vector<ll> G[110000];
stack<ll> st;
ll idx, scc;

ll tr(ll k){
   if(k > 0)   return k+n;
   else  return -k;
}

void add(ll a, ll b){
   ll u = tr(-a);
   ll v = tr(b);
   G[u].push_back(v);
   u = tr(-b);
   v = tr(a);
   G[u].push_back(v);
}
ll dfs(ll node){
   vt[node] = ++idx;
   st.push(node);
   ll lo = vt[node];
   for(auto i : G[node]){
      if(!vt[i])  lo = min(lo, dfs(i));
      else if(!fin[i]) lo = min(lo, vt[i]);
   }
   if(lo == vt[node]){
      scc++;
      vector<ll> B;
      while(!st.empty()){
         ll a = st.top();
         st.pop();
         B.push_back(a);
         fin[a] = scc;
         if(a == node)  break;
      }
      A[scc] = B;
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
      add(a, b);
   }
   for(ll i=1; i<=2*n; i++){
      if(!vt[i])  dfs(i);
   }
   for(ll i=1; i<=n; i++){
      if(fin[i] == fin[i+n]){
         cout << "0\n";
         return 0;
      }
   }
   cout << "1\n";
   for(ll i=1; i<=n; i++){
      if(fin[i] > fin[i+n])   cout << "1";
      else  cout << "0";
      if(i < n)   cout << " ";
   }
   cout << "\n";
   return 0;
}
