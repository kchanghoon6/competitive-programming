#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K, Q;
ll parent(ll node){
   if(node == 1)  return 0;
   return (node-2)/K+1;
}
ll depth(ll node){
   ll d = 0;
   while(node != 1){
      node = parent(node);
      d++;
   }
   return d;
}
ll LCA(ll u, ll v){
   if(K==1){
      return abs(u-v);
   }
   ll ret = 0;
   ll du = depth(u);
   ll dv = depth(v);
   if(du < dv){
      swap(u, v);
      swap(du, dv);
   }
   while(du-dv != 0){
      u = parent(u);
      ret++;
      du--;
   }
   while(u != v){
      u = parent(u);
      v = parent(v);
      ret += 2;
   }
   return ret;
}
int main(){
   scanf("%lld %lld %lld", &N, &K, &Q);
   for(ll i=0; i<Q; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      printf("%lld\n", LCA(a, b));
   }
   return 0;
}
