#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll T;
ll X[200000];
ll P[200000];
ll tree[200000];
vector<pair<ll, pll>> G;

void update_(ll N, ll i, ll val){
   while(i <= N){
      tree[i] += val;
      i += (i&(-i));
   }
}
ll sum_(ll i){
   ll ret = 0;
   while(i > 0){
      ret += tree[i];
      i -= (i&(-i));
   }
   return ret;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> T;
   while(T--){
      ll N, K;
      cin >> N >> K;
      for(ll i=1; i<=N; i++){
         cin >> X[i];
      }
      sort(X+1, X+N+1);
      for(ll i=1; i<=N; i++){
         P[i] = X[i];
      }
      for(ll i=0; i<K; i++){
         ll l, r, t;
         cin >> l >> r >> t;
         ll s = 1, e = N;
         ll nl = lower_bound(X+1, X+N+1, l) - X;
         ll nr = upper_bound(X+1, X+N+1, r) - X - 1;
         if(nl <= nr)   G.push_back({nr, {nl, t}});
      }
      sort(G.begin(), G.end());
      ll ans = 0;
      for(auto i : G){
         ll idx = i.ff;
         ll k = i.ss.ss-(sum_(i.ff)-sum_(i.ss.ff-1));
         while(k > 0 && idx >= i.ss.ff){
            if(sum_(idx) - sum_(idx - 1) == 0){
               update_(N, idx, 1);
               k--;
               ans++;
            }
            idx--;
         }
      }
      cout << N-ans << "\n";
      G.clear();
      for(ll i=1; i<=N; i++){
         tree[i] = 0;
      }
   }
   return 0;
}
