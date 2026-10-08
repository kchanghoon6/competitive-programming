#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll ,ll>
#define ff first
#define ss second
using namespace std;


ll N, M;
ll tree[200000];
vector<pll> G[200000];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> M;
   for(ll i=1; i<=M; i++){
      ll a, b, c;
      cin >> a >> b >> c;
      G[a].push_back({c, b});
      G[b].push_back({c, a});
   }
   ll maxi = 0;
   for(auto i : G[1]){
      pq.push(i);
   }
   tree[1] = 1;
   ll ans = 0;
   while(!pq.empty()){
      auto e = pq.top();
      pq.pop();
      if(tree[e.ss]) continue;
      tree[e.ss] = 1;
      ans += e.ff;
      maxi = max(maxi, e.ff);
      for(auto i : G[e.ss]){
         if(tree[i.ss]) continue;
         pq.push(i);
      }
   }
   cout << ans-maxi << "\n";




   return 0;
}
