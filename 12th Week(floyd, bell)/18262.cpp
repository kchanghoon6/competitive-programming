#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;

ll N, M;
vector<pair<pll, ll>> lis[1500];   // <<정점 번호, 간선길이>, 파이프크기
priority_queue<pll, vector<pll>, greater<pll>> pq; // <시작으로부터 길이, 정점 번호>
ll dist[1500];
vector<ll> F;
ll lb;


void Dijkstra(ll st){
   for(int i = 1; i <= N; i++){
      dist[i] = 1e9;
   }
   while(!pq.empty())   pq.pop();
   pq.push({0, st});
   dist[st] = 0;
   while(!pq.empty()){
      pll v = pq.top();
      pq.pop();
      if(dist[v.ss] != v.ff)  continue;
      for(auto w : lis[v.ss]){
         if(dist[w.ff.ff] > dist[v.ss] + w.ff.ss && w.ss >= lb){
            dist[w.ff.ff] = dist[v.ss] + w.ff.ss;
            pq.push({dist[w.ff.ff], w.ff.ff});
         }
      }
   }

}
int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=M; i++){
      ll a, b, c, d;
      scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
      lis[a].push_back({{b, c}, d});
      lis[b].push_back({{a, c}, d});
      F.push_back(d);
   }
   sort(F.begin(), F.end(), greater<ll>());
   ld result;
   for(auto i : F){
      lb = i;
      Dijkstra(1);
      result = max(result, (ld)lb/(ld)dist[N]);
   }
   result *= 1e6;
   printf("%lld\n", (ll)result);
   return 0;
}
