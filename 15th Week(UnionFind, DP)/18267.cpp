#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;
char A[200000];    // kind of each farm
vector<ll> B[200000];   // graph
ll G[200000];
ll H[200000];

ll find_(ll a, ll c){
   if(c == 0){
      if(G[a] == a)  return a;
      return G[a] = find_(G[a], 0);
   }
   else{
      if(H[a] == a)  return a;
      return H[a] = find_(H[a], 1);
   }
}
void union_(ll a, ll b, ll c){
   a = find_(a, c);
   b = find_(b, c);
   if(c == 0)  G[b] = a;
   else  H[b] = a;
}
ll kind_(char a){
   return (a == 'G') ? 0 : 1;
}

int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=N; i++){
      scanf(" %c", &A[i]);
   }
   for(ll i=1; i<=N; i++){
      G[i] = i;
      H[i] = i;
   }
   for(ll i=1; i<=N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      if(A[a] == A[b]){
         if(A[a] == 'G'){
            union_(a, b, 0);
         }
         else{
            union_(a, b, 1);
         }
      }
   }
   while(M--){
      ll a, b;
      char c;
      scanf("%lld %lld %c", &a, &b, &c);
      if(kind_(A[a]) != kind_(A[b]) || find_(a, kind_(A[a])) != find_(b, kind_(A[b])) || A[a] == c){
         printf("1");
      }
      else{
         printf("0");
      }
   }
   printf("\n");


   return 0;
}
