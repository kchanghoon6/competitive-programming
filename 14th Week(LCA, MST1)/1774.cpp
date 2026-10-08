#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define pdl pair<double, ll>
#define ff first
#define ss second
using namespace std;

pll A[50000];
vector<pdl> G[50000];
priority_queue<pdl, vector<pdl>, greater<pdl>> pq;
ll N, M;
ll tree[50000];

int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=N; i++){
      ll x, y;
      scanf("%lld %lld", &x, &y);
      A[i] = {x, y};
   }
   for(ll i=1; i<=N; i++){
      for(ll j=i+1; j<=N; j++){
         if(A[i] == A[j])  continue;
         double dx = abs((double)A[j].ff-A[i].ff);
         double dy = abs((double)A[j].ss-A[i].ss);
         double dist = sqrt(dx*dx+dy*dy);
         G[i].push_back({dist, j});
         G[j].push_back({dist, i});
      }
   }
   for(ll i=1; i<=M; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back({0, b});
      G[b].push_back({0, a});
   }
   for(auto i : G[1]){
      pq.push(i);
   }
   tree[1] = 1;
   double weight = 0;
   while(!pq.empty()){
      auto e = pq.top();
      pq.pop();
      if(tree[e.ss]) continue;
      tree[e.ss] = 1;
      weight += e.ff;
      for(auto i : G[e.ss]){
         if(tree[i.ss]) continue;
         pq.push(i);
      }
   }
   printf("%.2lf\n", weight);
   return 0;
}
