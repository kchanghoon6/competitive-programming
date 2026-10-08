#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

vector<pll> M[10][2000]; // M1[k=2]={{1, 2}}
vector<pll> B;
ll dpx[2000];
ll dpy[2000];
ll N, X, Y;

void choose(ll n, ll i, ll sx, ll sy, ll cnt, ll m, ll num){
   if(cnt == n){
      M[num][n].push_back({sx, sy});
      return;
   }
   if(i == m)  return;
   choose(n, i+1, sx+B[i].ff, sy+B[i].ss, cnt+1, m, num);
   choose(n, i+1, sx, sy, cnt, m, num);
}

int main(){
   scanf("%lld", &N);
   scanf("%lld %lld", &X, &Y);
   for(ll i=0; i<N; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      B.push_back({a, b});
   }
   for(ll i=1; i<=N/2; i++){
      choose(i, 0, 0, 0, 0, N/2, 0);
   }
   for(ll i=1; i<=N-(N/2); i++){
      choose(i, N/2, 0, 0, 0, N, 1);
   }

   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         dpx[i] += M[0][j].ff + M[1][i-j].ff;
      }
   }
   return 0;
}
