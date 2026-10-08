#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, A, B;
ll x, y;
vector<pll> G[200000];
ll visited[200000];

void dfs(ll v, ll cost, ll maxi){
   if(v == B){
      x = cost;
      y = maxi;
      return;
   }
   for(auto i : G[v]){
      if(!visited[i.ff]){
         visited[i.ff] = 1;
         dfs(i.ff, cost+i.ss, max(maxi, i.ss));
      }
   }
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> A >> B;
   for(ll i=1; i<=N-1; i++){
      ll a, b, c;
      cin >> a >> b >> c;
      G[a].push_back({b, c});
      G[b].push_back({a, c});
   }
   visited[A] = 1;
   dfs(A, 0, 0);
   cout << x-y << "\n";
   return 0;
}
