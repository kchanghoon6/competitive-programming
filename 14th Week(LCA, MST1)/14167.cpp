#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N;
pll A[50000];
vector<pll> G[50000];
priority_queue<pll, vector<pll>, greater<pll>> pq;
ll tree[50000];
int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      A[i] = {a, b};
   }
   for(ll i=1; i<=N; i++){
      for(ll j=i+1; j<=N; j++){
         ll dx = (A[i].ff-A[j].ff)*(A[i].ff-A[j].ff);
         ll dy = (A[i].ss-A[j].ss)*(A[i].ss-A[j].ss);
         ll dist = dx + dy;
         G[i].push_back({dist, j});
         G[j].push_back({dist, i});
      }
   }
   for(auto i : G[1]){
      pq.push(i);
   }
   ll result = 0;
   while(!pq.empty()){
      auto e = pq.top();
      pq.pop();
      if(tree[e.ss]) continue;
      tree[e.ss] = 1;
      result = max(result, e.ff);
      for(auto i : G[e.ss]){
         if(tree[i.ss]) continue;
         pq.push(i);
      }
   }
   printf("%lld\n", result);
   return 0;
}
