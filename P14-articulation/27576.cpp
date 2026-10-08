#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll n, idx, no;
pll A[10000];
vector<ll> G[10000];
ll vt[10000];

double dist(ll i, ll j){
   double dx = A[i].ff-A[j].ff;
   double dy = A[i].ss-A[j].ss;
   return (dx*dx + dy*dy);
}
ll dfs(ll node, ll par){
   vt[node] = ++idx;
   ll lo = vt[node];
   ll ch = 0;
   for(auto i : G[node]){
      if(i == par)   continue;
      if(vt[i])   lo = min(lo, vt[i]);
      else{
         ch++;
         ll k = dfs(i, node);
         if(node && k >= vt[node]){
            no = 1;
         }
         lo = min(lo, k);
      }
   }
   return lo;
}
ll check(double d){
   idx = 0, no = 0;
   for(ll i=0; i<=n; i++){
      G[i].clear();
      vt[i] = 0;
   }
   for(ll i=0; i<=n; i++){
      for(ll j=i+1; j<=n; j++){
         if(dist(i, j) <= d*d){
            G[i].push_back(j);
            G[j].push_back(i);
         }
      }
   }
   dfs(0, -1);
   for(ll i=0; i<=n; i++){
      if(!vt[i]) return false;
   }
   if(no)   return 0;
   return 1;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   A[0] = {0, 0};
   for(ll i=1; i<=n; i++){
      cin >> A[i].ff >> A[i].ss;
   }
   double s = 0, e = 1e15;
   double ans = 0;
   for(ll i=0; i<100; i++){
      double mid = (s+e)/2;
      if(check(mid)){
         e = mid;
         ans = e;
      }
      else{
         s = mid;
      }
   }
   cout << fixed << setprecision(15) << ans << "\n";
   return 0;
}
