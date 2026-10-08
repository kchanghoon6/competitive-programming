#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;
vector<pair<pll, ll>> A;
ll dist[200][200];
ll nxt[200][200];

int main(){
   int N, M;
   scanf("%d", &N);
   scanf("%d", &M);
   for(int i=0; i<M; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      A.push_back({{a, b}, c});
   }
   for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
         dist[i][j] = 1e9;
         if(i==j) dist[i][j] = 0;
      }
   }
   for(auto i : A){
      pll v = i.ff;
      nxt[v.ff][v.ss] = v.ss;
      dist[v.ff][v.ss] = min(dist[v.ff][v.ss], i.ss);
   }
   for(int m=1; m<=N; m++){
      for(int i=1; i<=N; i++){
         for(int j=1; j<=N; j++){
            if(dist[i][j] > dist[i][m] + dist[m][j]){
               dist[i][j] = dist[i][m] + dist[m][j];
               nxt[i][j] = nxt[i][m];
            }
         }
      }
   }
   for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
         printf("%lld ", (dist[i][j] == (ll)1e9) ? 0LL : dist[i][j]);
      }
      printf("\n");
   }

   for(int i=1; i<=N; i++){
      for(int j=1; j<=N; j++){
         if(dist[i][j] == 0 || dist[i][j] == (ll)1e9){
            printf("0\n");
            continue;
         }
         vector<ll> v;
         ll node = i;
         while(node != j){
            v.push_back(node);
            node = nxt[node][j];
         }
         v.push_back(j);
         printf("%lld ", (ll)v.size());
         for(auto k : v){
            printf("%lld ", k);
         }
         printf("\n");
      }
   }
   return 0;
}
