#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<pair<pll, ll>> A;
vector<pll> B;
ll dist[300][300];
bool hub[300];

int main(){
   ll N, M, K, Q;
   scanf("%lld %lld %lld %lld", &N, &M, &K, &Q);
   for(ll i=1; i<=K; i++){
      hub[i] = true;
   }
   for(ll i=0; i<M; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      A.push_back({{a, b}, c});
   }
   for(ll i=0; i<Q; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      B.push_back({a, b});
   }
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         dist[i][j] = 1e9;
         if(i==j){
            dist[i][j] = 0;
         }
      }
   }
   for(auto i : A){
      pll v = i.ff;
      dist[v.ff][v.ss] = min(dist[v.ff][v.ss], i.ss);
   }
   for(ll m=1; m<=N; m++){
      for(ll i=1; i<=N; i++){
         for(ll j=1; j<=N; j++){
            if(dist[i][j] > dist[i][m] + dist[m][j]){
               dist[i][j] = dist[i][m] + dist[m][j];
            }
         }
      }
   }
   ll cnt = 0;
   ll sum = 0;
   for(auto i : B){
      ll cur = 1e9;
      for(int k=1; k<=K; k++){
         cur = min(cur, dist[i.ff][k] + dist[k][i.ss]);
      }
      if(cur > 1e8)  continue;
      cnt++;
      sum += cur;
   }
   printf("%lld\n%lld\n", cnt, sum);
   return 0;
}
