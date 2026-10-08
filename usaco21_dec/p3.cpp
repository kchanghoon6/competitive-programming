#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll t, ans, n, k;
char A[100][100];
ll X[2] = {1, 0};
ll Y[2] = {0, 1};
void DFS(ll x, ll y, ll prev, ll num){
   if(x == n && y == n){
      ans++;
      return;
   }
   for(ll dir=0; dir<2; dir++){
      ll nx = x+X[dir];
      ll ny = y+Y[dir];
      if(nx <= n && ny <= n && A[nx][ny] == '.'){
         if(prev == -1) DFS(nx, ny, dir, num);
         else if(prev != dir && num < k)   DFS(nx, ny, dir, num+1);
         else if(prev == dir)   DFS(nx, ny, prev, num);
      }
   }

}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> t;
   while(t--){
      ans = 0;
      cin >> n >> k;
      for(ll i=1; i<=n; i++){
         for(ll j=1; j<=n; j++){
            cin >> A[i][j];
         }
      }
      DFS(1, 1, -1, 0);
      cout << ans << "\n";
   }


   return 0;
}
