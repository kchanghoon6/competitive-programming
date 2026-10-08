#include <bits/stdc++.h>
#define ll long long
#define plc pair<ll, char>
#define ff first
#define ss second
using namespace std;


ll k, n, scc, idx;
ll vt[50000];
ll fin[50000];
vector<ll> G[50000];
stack<ll> st;

ll tr1(plc a){
   if(a.ss == 'B')  return a.ff+k;
   return a.ff;
}
ll tr2(plc a){
   if(a.ss == 'R')  return a.ff+k;
   return a.ff;
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
      while(!st.empty()){
         ll a = st.top();
         st.pop();
         fin[a] = scc;
         if(a == node)  break;
      }
   }
   return lo;
}



int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> k >> n;
   for(ll i=0; i<n; i++){
      ll a, b, c;
      char ac, bc, cc;
      cin >> a >> ac >> b >> bc >> c >> cc;
      plc A[10];
      A[0] = {a, ac}, A[1] = {b, bc}, A[2] = {c, cc};
      for(ll p=0; p<3; p++){
         for(ll q=0; q<3; q++){
            if(p == q)  continue;
            G[tr2(A[p])].push_back(tr1(A[q]));
         }
      }
   }
   for(ll i=1; i<=2*k; i++){
      if(!vt[i])  dfs(i);
   }
   for(ll i=1; i<=k; i++){
      if(fin[i] == fin[i+k]){
         cout << "-1\n";
         return 0;
      }
   }
   for(ll i=1; i<=k; i++){
      if(fin[i] < fin[i+k])   cout << "R";
      else  cout << "B";
   }
   cout << "\n";

   return 0;
}
