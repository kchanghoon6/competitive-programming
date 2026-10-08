#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<pair<pair<pll, pll>, ll>> A;
ll X[4] = {1, -1, 0, 0};
ll Y[4] = {0, 0, 1, -1};
char G[50][50];
ll dist[50][50];
ll N, a, b;

void dijkstra(int sx, int sy){
   for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
         dist[i][j] = 1e9;
      }
   }
   priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
   dist[sx][sy] = 0;
   pq.push({0, {sx, sy}});
   while(!pq.empty()){
      pair<ll, pll> v = pq.top();
      pq.pop();
      ll x = v.ss.ff;
      ll y = v.ss.ss;
      if(dist[x][y] != v.ff)  continue;
      for(ll k=0; k<4; k++){
         ll nx = x+X[k];
         ll ny = y+Y[k];
         if(nx <= N && nx >= 1 && ny <= N && ny >=1){
            ll cost = (G[x][y-1] == G[nx][ny-1]) ? a : b;
            if(dist[nx][ny] > dist[x][y] + cost){
               dist[nx][ny] = dist[x][y] + cost;
               pq.push({dist[nx][ny], {nx, ny}});
            }
         }
      }
   }
}

int main(){
   scanf("%lld %lld %lld", &N, &a, &b);
   for(ll i=1; i<=N; i++){
      scanf("%s", G[i]);
   }
   ll maxi = 0;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         dijkstra(i, j);
         for(int x = 1; x <= N; x++){
            for(int y = 1; y <= N; y++){
               if(dist[x][y] < 1e8){
                  maxi = max(maxi, dist[x][y]);
               }
            }
         }
      }
   }
   printf("%lld\n", maxi);
   return 0;
}
