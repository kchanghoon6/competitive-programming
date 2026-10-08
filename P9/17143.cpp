#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll r, c, m;
pll S[20000];
ll V[20000];
ll D[20000];
ll Z[20000];
ll G[200][200];
ll A[20000];

void move(ll idx){
   ll dir = D[idx];
   if(dir == 1 || dir == 2){
      ll v = V[idx]%(2*(r-1));
      for(ll i=0; i<v; i++){
         if(dir == 1){
            if(S[idx].ff == 1)   dir = 2;
            else  S[idx].ff--;
         }
         if(dir == 2){
            if(S[idx].ff == r){
               dir = 1;
               S[idx].ff--;
            }
            else  S[idx].ff++;
         }
      }
   }
   else{
      ll v = V[idx]%(2*(c-1));
      for(ll i=0; i<v; i++){
         if(dir == 3){
            if(S[idx].ss == c)   dir = 4;
            else  S[idx].ss++;
         }
         if(dir == 4){
            if(S[idx].ss == 1){
               dir = 3;
               S[idx].ss++;
            }
            else  S[idx].ss--;
         }
      }
   }
   D[idx] = dir;
}




int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> r >> c >> m;
   for(ll i=1; i<=m; i++){
      cin >> S[i].ff >> S[i].ss >> V[i] >> D[i] >> Z[i];
   }
   for(ll i=1; i<=m; i++){
      G[S[i].ff][S[i].ss] = i;
   }
   ll res = 0;
   for(ll i=1; i<=c; i++){
      for(ll j=1; j<=r; j++){
         ll n = G[j][i];
         if(n == 0)  continue;
         res += Z[n];
         A[n] = 1;
         break;
      }
      for(ll j=1; j<=m; j++)  G[S[j].ff][S[j].ss] = 0;
      for(ll j=1; j<=m; j++){
         if(A[j]) continue;
         move(j);
         if(G[S[j].ff][S[j].ss]){
            if(Z[j] > Z[ G[S[j].ff][S[j].ss]]){
               A[G[S[j].ff][S[j].ss]] = 1;
               G[S[j].ff][S[j].ss] = j;
            }
            else{
               A[j] = 1;
            }
         }
         else  G[S[j].ff][S[j].ss] = j;

      }
   }
   cout << res << "\n";
   return 0;
}
