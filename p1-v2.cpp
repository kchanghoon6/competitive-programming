#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
using namespace std;

ll sp[300005][19];
ll c[300005];
ll req[300005];
ll lg[300005];

void build(ll n){
   for(ll i=2; i<=n; i++) lg[i] = lg[i/2] + 1;
   for(ll j=1; j<19; j++)
      for(ll i=1; i+(1<<j)-1<=n; i++)
         sp[i][j] = max(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
}

ll qmax(ll l, ll r){
   if(l > r) return 0;
   ll k = lg[r-l+1];
   return max(sp[l][k], sp[r-(1<<k)+1][k]);
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll T;
   cin >> T;
   while(T--){
      ll N, Q, C;
      cin >> N >> Q >> C;
      for(ll i=1; i<=N; i++){
         cin >> c[i];
         sp[i][0] = c[i];
         req[i] = 0;
      }
      req[N+1] = 0;
      build(N);

      vector<pll> pr(Q);
      vector<vector<ll>> at_a(N+2), at_h(N+2);
      for(ll i=0; i<Q; i++){
         cin >> pr[i].ff >> pr[i].ss;
         at_a[pr[i].ff].push_back(i);
         at_h[pr[i].ss].push_back(i);
      }

      bool fail = false;
      {
         vector<pll> sc(Q);
         for(ll i=0; i<Q; i++) sc[i] = pr[i];
         sort(sc.begin(), sc.end());
         multiset<ll> act;
         for(ll i=0; i<Q; i++){
            while(!act.empty() && *act.begin() <= sc[i].ff)
               act.erase(act.begin());
            if(!act.empty()){
               if(*act.begin() != sc[i].ss || *act.rbegin() != sc[i].ss){
                  fail = true;
                  break;
               }
            }
            act.insert(sc[i].ss);
         }
      }

      if(!fail){
         for(ll i=0; i<Q; i++){
            ll a = pr[i].ff, h = pr[i].ss;
            if(a+1 <= h-1)
               req[a] = max(req[a], qmax(a+1, h-1));
         }
         for(ll i=N; i>=2; i--){
            if(req[i] > 0 && c[i] > 0 && c[i] < req[i])
               req[i-1] = max(req[i-1], req[i]);
         }

         ll pfx = 0;
         vector<ll> snap(Q, 0);
         multiset<ll> act;
         for(ll i=1; i<=N && !fail; i++){
            if(i >= 2){
               for(ll idx : at_a[i-1])
                  act.insert(snap[idx]);
            }
            for(ll idx : at_h[i]){
               auto it = act.find(snap[idx]);
               if(it != act.end()) act.erase(it);
            }

            ll ub = C;
            if(!act.empty()) ub = min(ub, *act.begin());

            ll lb = 1;
            for(ll idx : at_h[i])
               lb = max(lb, snap[idx] + 1);
            if(c[i] == 0 && req[i] > 0 && pfx < req[i])
               lb = max(lb, req[i]);

            if(c[i] > 0){
               if(c[i] < lb || c[i] > ub){ fail = true; break; }
            } else{
               c[i] = lb;
               if(c[i] > ub || c[i] > C){ fail = true; break; }
            }
            pfx = max(pfx, c[i]);

            if(req[i] > 0 && pfx < req[i]){ fail = true; break; }

            for(ll idx : at_a[i]){
               snap[idx] = pfx;
               ll h = pr[idx].ss;
               if(c[h] > 0 && pfx >= c[h]){ fail = true; break; }
               if(pfx >= C){ fail = true; break; }
            }
         }
      }

      if(fail) cout << -1 << "\n";
      else{
         for(ll i=1; i<=N; i++)
            cout << c[i] << " \n"[i==N];
      }
   }
   return 0;
}
