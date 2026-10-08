#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll idx, flag;
ll vt[200000];
vector<ll> G[200000];
set<ll> S;
stack<pll> st;
ll A[200000];

ll dfs(ll node, ll par){
   vt[node] = ++idx;
   ll lo = vt[node];
   for(auto i : G[node]){
      if(i == par)   continue;
      if(vt[i]){
         lo = min(lo, vt[i]);
         if(vt[i] < vt[node]){
            st.push({node, i});
         }
      }

      else{
         st.push({node, i});
         ll d = dfs(i, node);
         ll cnt = 0;
         S.clear();
         if(d >= vt[node]){
            while(!st.empty()){
               auto a = st.top();
               st.pop();
               cnt++;
               S.insert(a.ff);   S.insert(a.ss);
               if(a.ff == node && a.ss == i) break;
            }
            if(S.size() < cnt)  flag = 1;
            if(S.size() == cnt){
               for(auto i : S){
                  if(++A[i] >= 2){
                     flag = 1;
                  }
               }
            }
         }
         lo = min(lo, d);
      }
   }
   return lo;
}

ll v, e;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> v >> e;
   for(ll i=0; i<e; i++){
      ll a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
   }
   for(ll i=1; i<=v; i++){
      if(!vt[i])  dfs(i, 0);
      if(flag){
         cout << "Not cactus";
         return 0;
      }
   }
   cout << "Cactus";


   return 0;
}
