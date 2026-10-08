#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[200005], C[200005];
ll d0[200005], d1[200005];
ll oc[200005];
ll st[200005];
ll cd[200005];
vector<ll> ch[200005];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin >> n;
   for(ll i=1; i<=n; i++) cin >> A[i];
   for(ll i=1; i<=n; i++) cin >> C[i];
   ll tot = 0;
   for(ll i=1; i<=n; i++) tot += C[i];

   vector<vector<ll>> cys;
   for(ll i=1; i<=n; i++){
      if(st[i]) continue;
      vector<ll> pa;
      ll u = i;
      while(!st[u]){
         st[u] = 1;
         cd[u] = pa.size();
         pa.push_back(u);
         u = A[u];
      }
      if(st[u] == 1){
         vector<ll> cy;
         for(ll j=cd[u]; j<(ll)pa.size(); j++){
            cy.push_back(pa[j]);
            oc[pa[j]] = 1;
         }
         cys.push_back(cy);
      }
      for(ll x : pa) st[x] = 2;
   }

   for(ll i=1; i<=n; i++){
      if(!oc[i]) ch[A[i]].push_back(i);
   }

   vector<ll> rts;
   for(auto& cy : cys) for(ll x : cy) rts.push_back(x);

   for(ll r : rts){
      vector<pair<ll,ll>> sk;
      sk.push_back({r, 0});
      while(!sk.empty()){
         auto& [v, s] = sk.back();
         if(s == 0){
            s = 1;
            for(ll c : ch[v]) sk.push_back({c, 0});
         }
         else{
            ll a = 0, b = 0;
            for(ll c : ch[v]){
               a += max(d0[c], d1[c]);
               b += max(d0[c]+C[c], d1[c]);
            }
            d0[v] = a;
            d1[v] = b;
            sk.pop_back();
         }
      }
   }

   ll sv = 0;
   for(auto& cy : cys){
      ll L = cy.size();
      if(L == 1){
         ll r = cy[0];
         sv += max(C[r]+d1[r], d0[r]);
      }
      else{
         ll best = LLONG_MIN;
         for(ll x0=0; x0<2; x0++){
            vector<vector<ll>> f(L, vector<ll>(2, LLONG_MIN));
            ll v0 = cy[0];
            if(x0 == 0) f[0][0] = d0[v0];
            else f[0][1] = d1[v0];
            for(ll k=1; k<L; k++){
               ll vk = cy[k], vp = cy[k-1];
               for(ll xk=0; xk<2; xk++){
                  ll dv = (xk == 0) ? d0[vk] : d1[vk];
                  for(ll xp=0; xp<2; xp++){
                     if(f[k-1][xp] == LLONG_MIN) continue;
                     ll ad = (xp == 0 && xk == 1) ? C[vp] : 0;
                     ll cand = f[k-1][xp] + dv + ad;
                     if(cand > f[k][xk]) f[k][xk] = cand;
                  }
               }
            }
            ll vL = cy[L-1];
            for(ll xL=0; xL<2; xL++){
               if(f[L-1][xL] == LLONG_MIN) continue;
               ll ad = (xL == 0 && x0 == 1) ? C[vL] : 0;
               ll cand = f[L-1][xL] + ad;
               if(cand > best) best = cand;
            }
         }
         sv += best;
      }
   }

   cout << tot-sv << "\n";
   return 0;
}
