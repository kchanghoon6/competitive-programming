#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;


ll N;
vector<ll> A[200000];
ll P[200000];

void make_tree(ll node, ll par){
   P[node] = par;
   for(auto i : A[node]){
      if(i == par) continue;
      make_tree(i, node);
   }
}
int main(){
   scanf("%lld", &N);
   for(ll i=0; i<N-1; i++){
      ll a, b;
      scanf("%lld %lld", &a, &b);
      A[a].push_back(b);
      A[b].push_back(a);
   }
   make_tree(1, 0);
   ll days = N-1;
   for(ll i=1; i<=N; i++){
      ll indegree = A[i].size();
      if(indegree > 1){
         if(i != 1) indegree--;
         ll inf = 1;
         while(inf < indegree+1){
            inf*=2;
            days++;
         }
      }
   }
   printf("%lld\n", days);
   return 0;
}
