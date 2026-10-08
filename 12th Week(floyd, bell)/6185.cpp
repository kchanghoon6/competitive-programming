#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<pair<pll, ll>> A;
ll B[20000];
ll dist[300][300];

int main(){
   ll N, M;
   scanf("%lld %lld", &N, &M);
   B[0] = 0;
   for(ll i=1; i<=M; i++){
      scanf("%lld", &B[i]);
   }
   B[M+1] = N;

   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         ll a;
         scanf("%lld", &a);
         A.push_back({{i, j}, a});
      }
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
   ll danger_sum = 0;
   for(ll i=0; i<=M; i++){
      danger_sum += dist[B[i]][B[i+1]];
   }
   printf("%lld\n", danger_sum);
   return 0;
}
