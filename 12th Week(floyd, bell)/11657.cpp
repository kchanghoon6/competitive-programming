#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N, M;
vector<pair<pll, ll>> A;
ll dist[700];

bool bellman_ford(ll st){
   for(ll i=1; i<=N; i++){
      dist[i] = 1e9;
   }
   dist[st] = 0;
   for(ll i=0; i<N; i++){
      for(auto j : A){
         if(dist[j.ff.ff] > 1e8) continue;
         if(dist[j.ff.ss] > dist[j.ff.ff] + j.ss){
            if(i==N-1)  return 1;
            dist[j.ff.ss] = dist[j.ff.ff] + j.ss;
         }
      }
   }
   return 0;
}
int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=M; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      A.push_back({{a, b}, c});
   }
   if(!bellman_ford(1)){
      for(ll i=2; i<=N; i++){
         if(dist[i] > 1e8) printf("-1\n");
         else  printf("%lld\n", dist[i]);
      }
   }
   else  printf("-1\n");

   return 0;
}
