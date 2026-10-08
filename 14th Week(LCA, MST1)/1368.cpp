#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N;
ll W[1000];
vector<pll> A[1000];
ll tree[1000];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &W[i]);
   }
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         ll a;
         scanf("%lld", &a);
         if(i == j)  continue;
         A[i].push_back({a, j});
         A[j].push_back({a, i});
      }
   }
   for(ll i=1; i<=N; i++){
      A[N+1].push_back({W[i], i});
      A[i].push_back({W[i], N+1});
   }
   for(auto i : A[1]){
      pq.push(i);
   }
   tree[1] = 1;
   ll price = 0;
   while(!pq.empty()){
      pll e = pq.top();
      pq.pop();
      if(tree[e.ss]) continue;
      tree[e.ss] = 1;
      price += e.ff;
      for(auto i : A[e.ss]){
         if(tree[i.ss]) continue;
         pq.push(i);
      }
   }
   printf("%lld\n", price);
   return 0;
}
