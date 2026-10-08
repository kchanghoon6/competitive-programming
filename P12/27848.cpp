#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll n, m;
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<pair<ll, pll>> G[300000];
ll A[300000];
ll dist[300000];
ll idx[300000];

void dijkstra(ll st){
   for(ll i=1; i<=n; i++)  dist[i] = 1e10;
   dist[st] = 0;
   pq.push({0, st});
   while(!pq.empty()){
      auto v = pq.top();
      pq.pop();
      if(v.ff != dist[v.ss])  continue;
      ll len = G[v.ss].size();
      ll t = A[v.ss] + v.ff;
      if(v.ss == st && v.ff == 0)   t = 0;
      while(idx[v.ss] < len && G[v.ss][idx[v.ss]].ff >= t){
         auto w = G[v.ss][idx[v.ss]];
         idx[v.ss]++;
         ll r = w.ff;
         ll d = w.ss.ff;
         ll s = w.ss.ss;
         if(dist[d] > s){
            dist[d] = s;
            pq.push({s, d});
         }
      }
   }
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n >> m;
   for(ll i=0; i<m; i++){
      ll c, r, d, s;
      cin >> c >> r >> d >> s;
      G[c].push_back({r, {d, s}});
   }
   for(ll i=1; i<=n; i++){
      sort(G[i].rbegin(), G[i].rend());
      cin >> A[i];
   }
   dijkstra(1);
   for(ll i=1; i<=n; i++){
      if(dist[i] > 1e9) cout << -1 << "\n";
      else  cout << dist[i] << "\n";
   }


   return 0;
}
