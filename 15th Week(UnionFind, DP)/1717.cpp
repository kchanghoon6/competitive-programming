#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;
ll P[(ll)2e6];

ll find_(ll a){
   if(a == P[a])   return a;
   return P[a] = find_(P[a]);
}
void union_(ll a, ll b){
   a = find_(a);
   b = find_(b);
   P[b] = a;
}

int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=0; i<=N; i++){
      P[i] = i;
   }
   for(ll i=0; i<M; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      if(a==0) union_(b, c);
      else{
         if(find_(b) == find_(c))   printf("YES\n");
         else  printf("NO\n");
      }
   }
   return 0;
}
