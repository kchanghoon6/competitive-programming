#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, N;
vector<ll> A[100050];
ll B[100050];
ll P[100050][30];
ll D[100050];

void make_tree(ll node, ll par){
   P[node][0] = par;
   D[node] = D[par]+1;
   for(auto i : A[node]){
      if(i == par)   continue;
      make_tree(i, node);
   }
}

ll LCA(ll u, ll v){
   ll ret = 0;
   if(D[u] < D[v]){
      swap(u, v);
   }
   for(ll i=28; i>=0; i--){
      if((1LL<<i) <= D[u]-D[v]){
         u = P[u][i];
         ret += (1LL<<i);
      }
   }
   if(u == v)  return ret;
   for(ll i=28; i>=0; i--){
      if(P[u][i] != P[v][i]){
         u = P[u][i];
         v = P[v][i];
         ret += (2LL<<i);
      }
   }
   return ret+2;
}

int main(){
   scanf("%lld", &t);
   while(t--){
      scanf("%lld", &N);
      for(ll i=0; i<N-1; i++){
         ll a, b;
         scanf("%lld %lld", &a, &b);
         A[a].push_back(b);
         A[b].push_back(a);
      }
      make_tree(1, 0);
      for(ll k=1; k<=28; k++){
         for(ll x=1; x<=N; x++){
            P[x][k] = P[P[x][k-1]][k-1];
         }
      }
      for(ll i=0; i<N; i++){
         scanf("%lld", &B[i]);
      }
      bool result = 1;
      for(ll i=0; i<N-1; i++){
         if(LCA(B[i], B[i+1]) > 3){
            result = 0;
            break;
         }
      }
      printf("%d\n", result);
      for(ll i=1; i<=N; i++){
         vector<ll>().swap(A[i]);
         B[i] = 0;
         D[i] = 0;
      }
      for(ll i=1; i<=N; i++){
         for(ll j=0; j<30; j++){
            P[i][j] = 0;
         }
      }
   }
   return 0;
}
