#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> sum[100050];
vector<ll> G[100050];
ll visited[100050];

ll N, M;

void update_(ll t, ll x, ll val){
   ll sz = G[t].size();
   while(x <= sz){
      sum[t][x] += val;
      x += x & (-x);
   }
}
ll sum_(ll t, ll x){
   ll ret = 0;
   while(x > 0){
      ret += sum[t][x];
      x -= x & (-x);
   }
   return ret;
}

ll find_(ll node, ll t){
   ll s = 1, e = G[node].size();
   while(s < e){
      ll mid = (s+e)/2;
      if(sum_(node, mid) >= t) e = mid;
      else s = mid+1;
   }
   return s;
}


void MFS(ll node){
   visited[node] = 1;
   cout << node << " ";
   // 주변 정점 tree에서 제거
   for(auto i : G[node]){
      ll idx = lower_bound(G[i].begin(), G[i].end(), node)-G[i].begin()+1;
      update_(i, idx, -1);
   }
   while(true){
      ll cnt = sum_(node, G[node].size());
      if(cnt <= 0) break;
      ll s = 0;
      if(cnt%2)   s = find_(node, (cnt+1)/2);
      else  s = find_(node, 1);
      ll next = G[node][s-1];
      MFS(next);
   }
}



int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N >> M;
   for(ll i=0; i<M; i++){
      ll a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
   }
   for(ll i=1; i<=N; i++){
      sort(G[i].begin(), G[i].end());
      G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
      ll len = G[i].size();
      sum[i].resize(len+1, 0);
      for(ll j=1; j<=len; j++){
         update_(i, j, 1);
      }
   }
   MFS(1);
   cout << "\n";

   return 0;
}
