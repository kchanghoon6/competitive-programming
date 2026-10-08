#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[5000];
vector<ll> P[5000];
ll K;
ll len = 1;
void tree(ll l, ll r, ll d){
   if(l > r)   return;
   ll mid = (l+r)/2;
   P[d].push_back(A[mid]);
   tree(l, mid-1, d+1);
   tree(mid+1, r, d+1);
}


int main(){
   scanf("%lld", &K);
   len = (1<<K)-1;
   for(ll i=0; i<len; i++){
      scanf("%lld", &A[i]);
   }
   tree(0, len-1, 0);
   for(ll i=0; i<K; i++){
      for(auto j : P[i]){
         printf("%lld ", j);
      }
      printf("\n");
   }
   return 0;
}
