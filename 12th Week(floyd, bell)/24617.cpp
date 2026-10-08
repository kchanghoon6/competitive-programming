#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N;
ll P[700][700];
bool reach[700][700];
int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         scanf("%lld", &P[i][j]);
      }
   }
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         ll k = P[i][j];
         reach[i][k] = true;
         if(k == i)  break;
      }
   }
   for(ll m=1; m<=N; m++){
      for(ll i=1; i<=N; i++){
         for(ll j=1; j<=N; j++){
            if(reach[i][m] && reach[m][j]){
               reach[i][j] = true;
            }
         }
      }
   }
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         ll k = P[i][j];
         if(reach[i][k] && reach[k][i]){
            printf("%lld\n", k);
            break;
         }
      }
   }
   return 0;
}
