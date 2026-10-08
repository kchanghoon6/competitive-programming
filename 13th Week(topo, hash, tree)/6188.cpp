#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pll pair<ll, ll>
using namespace std;

ll N, C;
vector<ll> P[200000];
queue<pll> q;
ll D[200000];
int main(){
   scanf("%lld %lld", &N, &C);
   for(ll i=0; i<C; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      P[a].push_back(b);
      P[a].push_back(c);
   }

   ll d = 1;
   q.push({1, d});
   while(!q.empty()){
      pll v = q.front();
      q.pop();
      D[v.ff] = v.ss;
      d = v.ss;
      for(auto i : P[v.ff]){
         q.push({i, d+1});
      }
   }
   for(ll i=1; i<=N; i++){
      printf("%lld\n", D[i]);
   }

   return 0;
}
