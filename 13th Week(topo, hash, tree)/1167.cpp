#include <bits/stdc++.h>
#define ff first
#define ss second
#define pll pair<ll, ll>
#define ll long long
using namespace std;

ll V;
vector<pll> A[200000];
bool visited[200000];
pll maxi;

void DFS(ll v, ll d){
   visited[v] = true;
   if(maxi.ff < d){
      maxi.ff = d;
      maxi.ss = v;
   }
   for(auto i : A[v]){
      if(!visited[i.ff]){
         DFS(i.ff, d+i.ss);
      }
   }
   return;
}

int main(){
   scanf("%lld", &V);
   for(ll i=1; i<=V; i++){
      ll a, c, b = 0;
      scanf("%lld", &a);
      while(true){
         scanf("%lld", &b);
         if(b == -1) break;
         scanf("%lld", &c);
         A[a].push_back({b, c});
         A[b].push_back({a, c});
      }
   }
   for(ll i=1; i<=200000; i++){
      visited[i] = false;
   }
   maxi = {0, 0};
   DFS(1, 0);
   pll w = maxi;

   for(ll i=1; i<=200000; i++){
      visited[i] = false;
   }
   maxi = {0, 0};
   DFS(w.ss, 0);
   printf("%lld\n", maxi.ff);

   return 0;
}
