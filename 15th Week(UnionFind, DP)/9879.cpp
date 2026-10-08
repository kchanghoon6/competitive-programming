#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll M, N;
ll A[1000][1000];
ll B[1000][1000];
ll X[] = {1, 0};
ll Y[] = {0, 1};
ll cnt;
ll P[1000000];
vector<ll> W;
struct Edge{
   ll w, u, v;
   bool operator<(const Edge& other) const{
      return w < other.w;
   }
};
vector<Edge> E;
ll find_(ll a){
   if(P[a] == a)  return a;
   return P[a] = find_(P[a]);
}
void union_(ll a, ll b){
   a = find_(a);
   b = find_(b);
   P[b] = a;
}

int main(){
   scanf("%lld %lld", &M, &N);
   for(ll i=0; i<M; i++){
      for(ll j=0; j<N; j++){
         scanf("%lld", &A[i][j]);
      }
   }
   for(ll i=0; i<M*N; i++){
      P[i] = i;
   }
   for(ll i=0; i<M; i++){
      for(ll j=0; j<N; j++){
         scanf("%lld", &B[i][j]);
         if(B[i][j] == 1)  W.push_back(i*N+j);
      }
   }
   for(ll i=0; i<M; i++){
      for(ll j=0; j<N; j++){
         for(ll k=0; k<2; k++){
            ll dx = i+X[k], dy = j+Y[k];
            if(dx < M && dx >= 0 && dy < N && dy >=0){
               ll u = i*N+j, v = dx*N+dy;
               ll w = abs(A[dx][dy]-A[i][j]);
               E.push_back({w, u, v});
            }
         }
      }
   }
   sort(E.begin(), E.end());
   ll ans = 0;
   for(auto e : E){
      union_(e.u, e.v);
      ans = max(ans, e.w);
      bool flag = 1;
      for(auto w : W){
         if(find_(w) != find_(W[0])){
            flag = 0;
            break;
         }
      }
      if(flag) break;
   }
   printf("%lld\n", ans);
   return 0;
}
