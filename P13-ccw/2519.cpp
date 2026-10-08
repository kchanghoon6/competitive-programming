#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

pll A1[10000];
pll A2[10000];
vector<ll> G[10000];
stack<ll> st;
ll vt[10000];
ll fin[10000];
ll scc, idx, n;

ll ccw(pll a, pll b, pll c){
   ll det = (b.ff-a.ff)*(c.ss-a.ss)-(c.ff-a.ff)*(b.ss-a.ss);
   if(det > 0) return 1;
   else if(det < 0) return -1;
   else return 0;
}
ll overlap(pll a, pll b, pll c, pll d){
   if(max(a.ff, b.ff) < min(c.ff, d.ff))  return 0;
   if(max(a.ss, b.ss) < min(c.ss, d.ss))  return 0;
   if(min(a.ff, b.ff) > max(c.ff, d.ff))  return 0;
   if(min(a.ss, b.ss) > max(c.ss, d.ss))  return 0;
   return 1;
}

ll tr(ll a){
   return a+3*n;
}
void add1(ll a, ll b){
   G[tr(a)].push_back(b);
   G[tr(b)].push_back(a);
}
void add2(ll a, ll b){
   G[a].push_back(tr(b));
   G[b].push_back(tr(a));
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

ll intersect(ll i, ll j){
   pll a = A1[i], b = A2[i];
   pll c = A1[j], d = A2[j];
   ll d1 = ccw(a, b, c);
   ll d2 = ccw(a, b, d);
   ll d3 = ccw(c, d, a);
   ll d4 = ccw(c, d, b);
   if(d1*d2 <= 0 && d3*d4 <= 0){
      if(!d1 && !d2 && !d3 && !d4)
         return overlap(a, b, c, d);
      return 1;
   }
   return 0;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   for(ll i=0; i<3*n; i++){
      ll a, b, c, d;
      cin >> a >> b >> c >> d;
      A1[i] = {a, b};   A2[i] = {c, d};
   }

   for(ll i=0; i<n; i++){
      ll a = 3*i, b = 3*i+1, c = 3*i+2;
      add2(a, b);
      add2(b, c);
      add2(a, c);
   }

   for(ll i=0; i<3*n; i++){
      for(ll j=i+1; j<3*n; j++){
         if(intersect(i, j)){
            add1(i, j);
         }
      }
   }

   for(ll i=0; i<6*n; i++){
      if(!vt[i])  dfs(i);
   }

   for(ll i=0; i<3*n; i++){
      if(fin[i] == fin[tr(i)]){
         cout << "-1\n";
         return 0;
      }
   }

   vector<ll> ans;
   for(ll i=0; i<3*n; i++){
      if(fin[i] < fin[tr(i)]) ans.push_back(i+1);
   }
   cout << ans.size() << "\n";
   if(ans.size() > 0){
      for(auto i : ans) cout << i << " ";
   }
   cout << "\n";
   return 0;
}
