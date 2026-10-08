#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;
vector<pair<pll, ll>> A;
ll dist[700][700];
vector<ll> f;
ll cnt[700];


int main(){
   ll P, F, C;
   scanf("%lld %lld %lld", &P, &F, &C);

   for(ll i=1; i<=F; i++){
      ll a;
      scanf("%lld", &a);
      f.push_back(a);
   }
   for(ll i=1; i<=C; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      A.push_back({{a, b}, c});
   }
   for(ll i=1; i<=P; i++){
      for(ll j=1; j<=P; j++){
         dist[i][j] = 1e9;
         if(i==j){
            dist[i][j] = 0;
         }
      }
   }
   for(auto i : A){
      pll v = i.ff;
      dist[v.ff][v.ss] = min(dist[v.ff][v.ss], i.ss);
      dist[v.ss][v.ff] = min(dist[v.ss][v.ff], i.ss);
   }
   for(ll m=1; m<=P; m++){
      for(ll i=1; i<=P; i++){
         for(ll j=1; j<=P; j++){
            if(dist[i][j] > dist[i][m] + dist[m][j]){
               dist[i][j] = dist[i][m] + dist[m][j];
            }
         }
      }
   }
   for(ll i=1; i<=P; i++){
      for(auto k : f){
         cnt[i] += dist[i][k];
      }
   }
   pll mini = {(ll)1e9, 0};
   for(ll i=1; i<=P; i++){
      if(mini.ff > cnt[i]){
         mini.ff = cnt[i];
         mini.ss = i;
      }
   }
   printf("%lld\n", mini.ss);
   return 0;
}
