#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N, M;
ll A[1500][1500];
ll dist[1500][1500][2];  // [i][j][has_orange]
ll prev_dir[1500][1500];
ll X[] = {1, -1, 0, 0};
ll Y[] = {0, 0 , 1, -1};
// 시작으로부터 거리, 정점번호
priority_queue<pair<pll, pll>, vector<pair<pll, pll>>, greater<pair<pll, pll>>> pq;

void Dijkstra(ll st_i, ll st_j){
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=M; j++){
         dist[i][j][0] = dist[i][j][1] = 1e9;
         prev_dir[i][j] = -1;
      }
   }
   bool isOrange = false;
   if(A[1][1] == 2)  isOrange=true;
   pq.push({{0, isOrange}, {st_i, st_j}});
   dist[st_i][st_j][isOrange] = 0;

   while(!pq.empty()){
      pair<pll, pll> v = pq.top();
      pq.pop();
      ll x = v.ss.ff;
      ll y = v.ss.ss;
      ll cur = A[x][y];
      ll cur_dist = v.ff.ff;
      isOrange = v.ff.ss;

      if(dist[x][y][isOrange] != cur_dist)  continue;

      for(ll i=0; i<4; i++){
         ll nx = X[i]+x;
         ll ny = Y[i]+y;
         if(nx <= N && nx >=1 && ny <= M && ny >= 1){
            ll a = A[nx][ny];
            if(a == 0)  continue;
            bool nextOrange = isOrange;
            if(a == 2)  nextOrange = true;
            if(a == 3 && !nextOrange) continue;
            if(cur == 4){
               if(prev_dir[x][y] != i) continue;
               nextOrange = false;
            }

            if(dist[nx][ny][nextOrange] > dist[x][y][isOrange] + 1){
               dist[nx][ny][nextOrange] = dist[x][y][isOrange] + 1;
               prev_dir[nx][ny] = i;
               pq.push({{dist[nx][ny][nextOrange], nextOrange}, {nx, ny}});
            }
         }
      }
   }
}
int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=M; j++){
         scanf("%lld", &A[i][j]);
      }
   }
   Dijkstra(1, 1);
   ll ans = min(dist[N][M][0], dist[N][M][1]);
   if(ans > 1e8) printf("-1\n");
   else{
      printf("%lld\n", ans);
   }
   return 0;
}
