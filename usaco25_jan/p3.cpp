#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll F[1001][1001];
ll fr[2001];
ll T[2][1001][1001];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);

   cin >> n;
   for(ll i=1; i<=n; i++)
      for(ll j=1; j<=n; j++){
         cin >> F[i][j];
         fr[F[i][j]]++;
      }

   ll pr[2], pc[2], cnt=0;
   for(ll i=1; i<=n; i++)
      for(ll j=1; j<=n; j++)
         if(fr[F[i][j]]==1)
            pr[cnt]=i, pc[cnt]=j, cnt++;
   if(cnt==1) pr[1]=pr[0], pc[1]=pc[0];

   for(ll k=0; k<2; k++)
      for(ll i=1; i<=n; i++)
         for(ll j=1; j<=n; j++)
            T[k][i][j] = fr[F[i][pc[k]]] + fr[F[pr[k]][j]];

   ll b=0;
   bool dn=false;
   for(ll i=1; i<=n && !dn; i++)
      for(ll j=1; j<=n && !dn; j++){
         if(T[0][i][j]<T[1][i][j]) dn=true;
         else if(T[0][i][j]>T[1][i][j]){ b=1; dn=true; }
      }

   for(ll i=1; i<=n; i++){
      for(ll j=1; j<=n; j++){
         if(j>1) cout << ' ';
         cout << T[b][i][j];
      }
      cout << '\n';
   }
   return 0;
}
