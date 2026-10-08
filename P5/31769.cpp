#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll N, K;
ll A[500000];
priority_queue<pll, vector<pll>, greater<pll>> pq;
map<ll, vector<ll>> B;
map<ll, bool> visited;

void DFS(ll t){
   for(auto i : B[t]){
      if(i != 0 && !visited[i]){
         visited[i] = 1;
         if(i != 0)  DFS(i);
      }
   }
   return;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> K;
   for(ll i=1; i<=N; i++){
      cin >> A[i];
   }
   for(ll i=1; i<=K; i++){
      pq.push({A[i], i});
      B[A[i]].push_back(0);
   }

   for(ll i=K+1; i<=N; i++){
      auto v = pq.top();
      pq.pop();
      ll t = A[i]+v.ff;
      pq.push({t, v.ss});
      B[t].push_back(v.ff);
   }

   ll t = pq.top().ff;
   cout << t << "\n";
   visited[t] = 1;
   DFS(t);
   for(ll i=1; i<=K; i++){
      cout << (visited[A[i]]);
   }
   cout << "\n";

   return 0;
}
