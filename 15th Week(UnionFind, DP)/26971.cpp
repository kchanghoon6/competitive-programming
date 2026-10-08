#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, M;
vector<ll> G[300000];
ll degree[300000];
ll visited[300000];
vector<ll> A;
ll B[300000];
priority_queue<pll, vector<pll>, greater<pll>> pq;
ll P[300000];
ll S[300000];
ll O[300000];

ll find_(ll a){
   if(P[a] == a)  return a;
   return P[a] = find_(P[a]);
}
ll unite(ll a, ll b){
   a = find_(a); b = find_(b);
   if(a == b) return S[a];
   if(S[a] < S[b]) swap(a,b);
   P[b] = a;
   S[a] += S[b];
   return S[a];
}

int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=M; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      G[a].push_back(b);
      G[b].push_back(a);
      degree[a]++;
      degree[b]++;
   }

   for(ll i=1; i<=N; i++){
      pq.push({degree[i], i});
   }
   while(!pq.empty()){
      auto v = pq.top();
      pq.pop();
      if(visited[v.ss]) continue;
      visited[v.ss] = 1;
      O[v.ss] = v.ff;
      A.push_back(v.ss);
      for(auto i : G[v.ss]){
         if(visited[i]) continue;
         degree[i]--;
         pq.push({degree[i], i});
      }
   }
   reverse(A.begin(), A.end());

   for(ll i=1; i<=N; i++){
      P[i] = i;
      S[i] = 1;
   }

   ll ans = 0;
   ll s = 1;
   for(auto i : A){
      B[i] = 1;
      for(auto j : G[i]){
         if(B[j]){
            ll k = unite(i, j);
            s = max(s, k);
         }
      }
      ans = max(ans, O[i] * s);
   }

   printf("%lld\n", ans);
   return 0;
}
