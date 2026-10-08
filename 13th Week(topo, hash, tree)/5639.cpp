#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll A[20000];
ll R[1000030];
ll L[1000030];
queue<ll> q;

void preorder(ll v, ll node){
   if(node > v){
      if(R[v] == 0){
         R[v] = node;
      }
      else{
         preorder(R[v], node);
      }
   }
   else{
      if(L[v] == 0){
         L[v] = node;
      }
      else{
         preorder(L[v], node);
      }
   }
}
void postorder(ll v){
   if(L[v] != 0)  postorder(L[v]);
   if(R[v] != 0)  postorder(R[v]);
   printf("%lld\n", v);
}
int main(){

   ll a;
   ll b = 0;
   while(scanf("%lld", &a) != EOF){
      A[b] = a;
      b++;
   }
   b--;
   ll root = A[0];
   for(ll i=1; i<=b; i++){
      preorder(root, A[i]);
   }
   postorder(root);

   return 0;
}
