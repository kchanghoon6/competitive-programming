#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll V[200005], W[200005], A[200005], E[200005], D[200005];
ll dp[200005][2], pa[200005][2];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll T, m;
   cin >> T >> m;
   while(T--){
      ll n;
      cin >> n;
      for(ll i=1; i<=n; i++) cin >> V[i];
      ll tot = 0, bok = 0;
      vector<pll> bst;
      for(ll d=0; d<2; d++){
         for(ll i=1; i<=n; i++) W[i] = (d == 0) ? V[i] : V[n+1-i];
         for(ll i=0; i<=n+2; i++) A[i] = 0;
         for(ll i=1; i<=n; i++){
            ll df = W[i]-A[i-1]-A[i];
            if(df > 0){
               ll tk = (i < n) ? min(W[i+1], df) : 0;
               A[i+1] = tk;
               A[i] += df-tk;
            }
         }
         if(d == 0)  for(ll i=1; i<=n; i++) tot += A[i];
         if(m == 0)  break;
         vector<pll> cur;
         ll ok = 1, i = 1;
         while(i <= n){
            if(!A[i]){ i++; continue; }
            ll l = i, r = i;
            while(r+1 <= n && A[r+1]) r++;
            if(l == r)  cur.push_back({l, A[l]});
            else{
               for(ll e=0; e<2; e++) dp[l][e] = (e == 1 || A[l+1] <= W[l]-A[l]);
               for(ll k=l+1; k<=r-1; k++){
                  for(ll e=0; e<2; e++){
                     dp[k][e] = 0;
                     for(ll pe=0; pe<2; pe++){
                        if(!dp[k-1][pe])  continue;
                        ll b = 0;
                        if(pe == 1)  b += A[k-1];
                        if(e == 0)  b += A[k+1];
                        if(b <= W[k]-A[k]){
                           dp[k][e] = 1;
                           pa[k][e] = pe;
                           break;
                        }
                     }
                  }
               }
               ll le = -1;
               for(ll e=0; e<2; e++){
                  if(dp[r-1][e] && (e == 0 || A[r-1] <= W[r]-A[r])){ le = e; break; }
               }
               if(le < 0){ ok = 0; break; }
               E[r-1] = le;
               for(ll k=r-1; k>l; k--) E[k-1] = pa[k][E[k]];
               for(ll k=l; k<=r; k++) D[k] = 0;
               for(ll k=l; k<r; k++){
                  if(E[k])  D[k+1]++;
                  else  D[k]++;
               }
               queue<ll> q;
               for(ll k=l; k<=r; k++){
                  if(!D[k])  q.push(k);
               }
               while(!q.empty()){
                  ll u = q.front();
                  q.pop();
                  cur.push_back({u, A[u]});
                  if(u > l && E[u-1] == 0 && --D[u-1] == 0)  q.push(u-1);
                  if(u < r && E[u] == 1 && --D[u+1] == 0)  q.push(u+1);
               }
            }
            i = r+1;
         }
         if(ok && (!bok || cur.size() < bst.size())){
            bok = 1;
            bst.clear();
            for(auto j : cur) bst.push_back({(d == 0) ? j.ff : n+1-j.ff, j.ss});
         }
      }
      if(m > 0 && !bok){
         for(ll i=1; i<=n; i++) W[i] = V[i];
         bst.clear();
         for(ll i=1; i<=n; i++){
            if(!W[i])  continue;
            ll t = (i < n) ? min(W[i], W[i+1]) : 0;
            if(t){
               if(!bst.empty() && bst.back().ff == i+1)  bst.back().ss += t;
               else  bst.push_back({i+1, t});
               W[i] -= t;
               W[i+1] -= t;
               if(i+2 <= n)  W[i+2] = max(W[i+2]-t, 0LL);
            }
            if(W[i]){
               if(!bst.empty() && bst.back().ff == i)  bst.back().ss += W[i];
               else  bst.push_back({i, W[i]});
               W[i] = 0;
            }
         }
      }
      cout << tot << "\n";
      if(m > 0){
         cout << bst.size() << "\n";
         for(auto j : bst) cout << j.ff << " " << j.ss << "\n";
      }
   }
   return 0;
}
