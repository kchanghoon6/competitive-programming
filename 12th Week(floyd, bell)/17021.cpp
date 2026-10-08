#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mod 1000000007LL
#define pll pair<ll, ll>
using namespace std;

vector<pll> A;
ll D[15000];
char end_char[200000];
vector<char> end_kind;
ll G[10000];
ll Alpha[50];

ll modpow(ll a, ll r){
   ll t = 1;
   a%=mod;
   while(r>0){
      if(r & 1){
         t *= a;
         t %= mod;
      }
      a = (a*a)%mod;
      r = r >> 1;
   }
   return t;
}


int main(){
   ll N, M, K;
   scanf("%lld %lld %lld", &N, &M, &K);

   for(ll i=0; i<N; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      A.push_back({a, b});
   }
   for(ll i=0; i<M; i++){
      char a;
      scanf(" %c", &a);
      Alpha[a-'A']++;
   }
   D[0] = 1;
   for(ll i=0; i<K; i++){
      for(auto j : A){
         if(i + j.ff <= K){
            D[i+j.ff] += D[i];
            D[i+j.ff] %= mod;
         }
      }
   }
   for(auto i : A){
      if(K-i.ff >= 0)   G[i.ss] += D[K-i.ff];
      G[i.ss] %= mod;
   }
   ll result = 1;
   for(ll i=0; i<26; i++){
      if(Alpha[i] == 0) continue;
      ll sum = 0;
      for(ll j=1; j<=N; j++){
         if(G[j] == 0)  continue;
         sum += modpow(G[j], Alpha[i]);
         sum %= mod;
      }
      result *= sum;
      result %= mod;
   }
   printf("%lld\n", result);
   return 0;
}
