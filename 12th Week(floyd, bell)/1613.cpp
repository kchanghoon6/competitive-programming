#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
using namespace std;

bool reach[500][500];
vector<pll> S;

int main(){
   ll N, K;
   scanf("%lld %lld", &N, &K);
   for(ll i=1; i<=K; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      reach[a][b] = true;
   }
   ll s;
   scanf("%lld", &s);
   for(ll i=1; i<=s; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      S.push_back({a, b});
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
   for(auto i : S){
      if(reach[i.ff][i.ss]) printf("-1\n");
      else if(reach[i.ss][i.ff]) printf("1\n");
      else  printf("0\n");
   }
   return 0;
}
