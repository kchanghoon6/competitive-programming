#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, M;
ll A[1500][1500];
ll tree[1500][1500];

void update_(ll x, ll y, ll val){
   ll yy = y;
   while(x <= 1100){
      y = yy;
      while(y <= 1100){
         tree[x][y] += val;
         y += (y & (-y));
      }
      x += (x & (-x));
   }
}
ll sum_(ll x, ll y){
   ll ret = 0;
   ll yy = y;
   while(x > 0){
      y = yy;
      while(y > 0){
         ret += tree[x][y];
         y -= (y & (-y));
      }
      x -= (x & (-x));
   }
   return ret;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> M;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         cin >> A[i][j];
         update_(i, j, A[i][j]);
      }
   }
   for(ll i=0; i<M; i++){
      ll w;
      cin >> w;
      if(w == 0){
         ll x, y, c;
         cin >> x >> y >> c;
         update_(x, y, c-A[x][y]);
         A[x][y] = c;
      }
      else{
         ll x1, x2, y1, y2;
         cin >> x1 >> y1 >> x2 >> y2;
         cout << sum_(x2, y2) - sum_(x1-1, y2) - sum_(x2, y1-1) + sum_(x1-1, y1-1) << "\n";
      }
   }


   return 0;
}
