// 위상정렬해서 하면 됨
#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, A, B;
set<ll> G[300000];
map<ll, ll> D;
ll C[300000];
ll E[300000];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> A >> B;
   for(ll i=0; i<N; i++){
      ll n, d;
      cin >> n >> d;
      D[d] = i;
      C[i] = n;
      E[i] = d;
   }

   for(ll i=0; i<N; i++){
      if(D.find(A-E[i]) != D.end()){
         G[i].insert(D[A-E[i]]);
      }
      if(D.find(B-E[i]) != D.end()){
         G[i].insert(D[B-E[i]]);
      }
   }
   queue<ll> q;
   for(ll i=0; i<N; i++){
      if(G[i].size() == 1) q.push(i);
   }
   ll ans = 0;
   while(!q.empty()){
      auto v = q.front();
      q.pop();
      if(G[v].size()!=1) continue;
      ll pr = *G[v].begin();
      // cout << v << " " << pr << " ";
      if(v == pr){
         ans += C[v]/2;
         C[v] = (C[v]%2) ? 1 : 0;
         G[v].clear();
      }
      else{
         ll add = min(C[v], C[pr]);
         ans += add;
         C[v] -= add; C[pr] -= add;
         // cout << add << " ";
         G[v].clear();
         G[pr].erase(v);
         if(G[pr].size() == 1)   q.push(pr);
      }
      // cout << "\n";
   }
   cout << ans << "\n";
   return 0;
}
