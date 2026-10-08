#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll n, s;
set<pll> E;
vector<ll> G[100000];
ll H[100000];
ll V[100000];
ll R[100000];
ll C[100000];
ll vt[100000];
pll RE[100000];
ll flag = 0;
pll p;
ll ans;

void dfs(ll node, ll par){
   vt[node] = 1;
   for(auto i : G[node]){
      if(vt[i])   continue;
      dfs(i, node);
      C[node] += C[i] + 1;
   }
   pll edge;
   if(R[node]){
      edge = RE[node];
   } else{
      ll d = par - node;
      if(d == 1 || d == -1){
         ll l = min(node, par);
         edge = {l+1, l+1+n};
      } else{
         ll t = min(node, par);
         edge = {t+n, t+n+1};
      }
   }
   if(C[node]+1 == s){
      if(!ans || edge < p) p = edge;
      ans++;
   }
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n >> s;
   for(ll i=0; i<n*n-1; i++){
      ll u, v;
      cin >> u >> v;
      ll mini = min(u, v);
      ll maxi = max(u, v);
      ll diff = maxi-mini;
      if(diff == n){
         V[mini] = 1;
      }
      if(diff == 1){
         H[mini] = 1;
      }
   }
   for(ll i=1; i<=n*n; i++){
      if(!V[i] && i+n<=n*n){
         if((i-1)%n == 0){
            R[i] = 1;
            RE[i] = {i, i+n};
         }
         else if(i%n == 0){
            R[i-1] = 1;
            RE[i-1] = {i, i+n};
         }
         else{
            G[i].push_back(i-1);
            G[i-1].push_back(i);
         }
      }
      if(!H[i] && i%n!=0){
         if(i<=n){
            R[i] = 1;
            RE[i] = {i, i+1};
         }
         else if(i>n*(n-1)){
            R[i-n] = 1;
            RE[i-n] = {i, i+1};
         }
         else{
            G[i-n].push_back(i);
            G[i].push_back(i-n);
         }
      }
   }

   p = {0, 0};
   for(ll i=1; i<=n*n; i++){
      if(i%n == 0)   continue;
      if(i > n*(n-1)) continue;
      if(!vt[i] && R[i]){
         dfs(i, -1);
      }
   }
   cout << ans << "\n";
   if(ans > 0)
      cout << p.ff << " " << p.ss << "\n";
   else
      cout << "0 0\n";
   return 0;
}
