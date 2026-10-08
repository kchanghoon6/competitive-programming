#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll N, U;
char G[2010][2010];
ll H[1005][1005];


ll cost(ll i, ll j){
   ll cnt = 0;
   if(G[i][j] == '.')   cnt++;
   if(G[i][N-1-j] == '.') cnt++;
   if(G[N-1-i][j] == '.') cnt++;
   if(G[N-1-i][N-1-j] == '.') cnt++;
   return min(cnt, 4-cnt);
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> U;
   for(ll i=0; i<N; i++){
      cin >> G[i];
   }
   ll result = 0;
   for(ll i=0; i<N/2; i++){
      for(ll j=0; j<N/2; j++){
         H[i][j] = cost(i, j);
         result += H[i][j];
      }
   }
   cout << result << "\n";
   while(U--){
      ll x, y;
      cin >> x >> y;
      x--;
      y--;

      ll i = min(x, N-1-x);
      ll j = min(y, N-1-y);
      result -= H[i][j];
      if(G[x][y] == '.')   G[x][y] = '#';
      else  G[x][y] = '.';
      H[i][j] = cost(i, j);
      result += H[i][j];
      cout << result << "\n";
   }



   return 0;
}
