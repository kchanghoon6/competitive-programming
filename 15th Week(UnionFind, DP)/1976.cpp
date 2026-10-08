#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, M;
ll P[5000];
ll A[5000];

ll find_(ll a){
   if(a == P[a])  return a;
   return P[a] = find_(P[a]);
}

void union_(ll a, ll b){
   a = find_(a);
   b = find_(b);
   P[b] = a;
}

int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=N; i++){
      P[i] = i;
   }
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         ll a;
         scanf("%lld", &a);
         if(a==1) union_(i, j);
      }
   }
   for(ll i=1; i<=M; i++){
      scanf("%lld", &A[i]);
   }
   ll flag = 0;
   ll par = find_(A[1]);
   for(ll i=2; i<=M; i++){
      if(par != find_(A[i])){
         printf("NO\n");
         flag = 1;
         break;
      }
   }
   if(!flag)   printf("YES\n");
   return 0;
}
