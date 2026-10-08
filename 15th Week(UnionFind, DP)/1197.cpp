#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll ,ll>
#define ff first
#define ss second
using namespace std;


ll P[20000];
priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
ll V, E;

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
   scanf("%lld %lld", &V, &E);
   for(ll i=1; i<=E; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      pq.push({c, {a, b}});
   }
   for(ll i=1; i<=V; i++){
      P[i] = i;
   }
   ll weight = 0;
   while(!pq.empty()){
      auto e = pq.top();
      pll nodes = e.ss;
      pq.pop();
      if(find_(nodes.ff) != find_(nodes.ss)){
         union_(nodes.ff, nodes.ss);
         weight += e.ff;
      }
   }
   printf("%lld\n", weight);

   return 0;
}
