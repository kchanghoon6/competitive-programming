#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll N, P;
pll A[3000000];   // post
pll B[3000000];   // cows
ll G[1100][1100];


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> P;
   for(ll i=0; i<P; i++){
      cin >> A[i].ff >> A[i].ss;
   }
   A[P] = A[0];
   ll t = 0;
   for(ll i=0; i<P; i++){
      ll x = A[i].ff, y = A[i].ss;
      ll nx = A[i+1].ff, ny = A[i+1].ss;
      if(x < nx){
         for(ll j=x; j<nx; j++){
            G[j][y] = t;
            t++;
         }
      }
      if(x > nx){
         for(ll j=x; j>nx; j--){
            G[j][y] = t;
            t++;
         }
      }
      if(y < ny){
         for(ll j=y; j<ny; j++){
            G[x][j] = t;
            t++;
         }
      }
      if(y > ny){
         for(ll j=y; j>ny; j--){
            G[x][j] = t;
            t++;
         }
      }
   }
   for(ll i=0; i<N; i++){
      ll sx, sy, ex, ey;
      cin >> sx >> sy >> ex >> ey;
      ll d = abs(G[ex][ey]-G[sx][sy]);
      cout << min(d, t-d) << "\n";
   }
   return 0;
}
