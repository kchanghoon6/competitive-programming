#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll n, h, k, q;
ll bs = 200003, m1 = 998244353, m2 = (ll)1e9+7;
ll A[200005], W[200005];
ll CT[1000005], CW[1000005];
ll PT[1000006], PV[1000006];

ll pw(ll a, ll b, ll m){
   ll r = 1; a %= m;
   while(b>0){
      if(b&1) r = r*a%m;
      a = a*a%m;
      b>>=1;
   }
   return r;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> n >> h;
   for(ll i=1; i<=n; i++) cin >> A[i];
   cin >> k;
   for(ll i=0; i<k; i++){
      ll x; cin >> x;
      W[x] = 1;
   }
   ll m = n-h;
   ll bi1 = pw(bs, m1-2, m1), bi2 = pw(bs, m2-2, m2);
   ll pw1 = pw(bs, m-1, m1), pw2 = pw(bs, m-1, m2);
   set<pll> hw, hn;
   deque<ll> dq;
   for(ll i=1; i<=h; i++){
      if(W[i])   hw.insert({A[i], i});
      else   hn.insert({A[i], i});
   }
   for(ll i=h+1; i<=n; i++) dq.push_back(i);
   ll h1 = 0, h2 = 0, p1 = 1, p2 = 1;
   for(ll i=0; i<m; i++){
      h1 = (h1+dq[i]*p1)%m1;
      h2 = (h2+dq[i]*p2)%m2;
      if(i < m-1)   p1 = p1*bs%m1, p2 = p2*bs%m2;
   }
   map<ll, ll> mp;
   mp[h1*m2+h2] = 0;
   ll np = 0, cs = -1, cl = -1;
   for(ll s=0; s<5*n; s++){
      ll c;
      if(!hw.empty()){
         pll f = *hw.begin();
         c = f.ss;
         hw.erase(hw.begin());
      }
      else{
         pll f = *hn.begin();
         c = f.ss;
         hn.erase(hn.begin());
      }
      CT[np] = A[c];
      CW[np] = W[c];
      np++;
      ll d = dq.front(); dq.pop_front();
      if(W[d])   hw.insert({A[d], d});
      else   hn.insert({A[d], d});
      dq.push_back(c);
      h1 = (h1-d+m1)%m1*bi1%m1;
      h1 = (h1+c*pw1)%m1;
      h2 = (h2-d+m2)%m2*bi2%m2;
      h2 = (h2+c*pw2)%m2;
      ll ch = h1*m2+h2;
      if(mp.count(ch)){
         cs = mp[ch];
         cl = s+1-cs;
         break;
      }
      mp[ch] = s+1;
   }
   for(ll i=0; i<np; i++){
      PT[i+1] = PT[i]+CT[i];
      PV[i+1] = PV[i]+CW[i];
   }
   cin >> q;
   while(q--){
      ll t; cin >> t;
      if(cs == -1){
         ll j = upper_bound(PT, PT+np+1, t)-PT-1;
         cout << PV[j] << "\n";
      }
      else{
         ll cyt = PT[cs+cl]-PT[cs];
         ll cyw = PV[cs+cl]-PV[cs];
         if(t < PT[cs]){
            ll j = upper_bound(PT, PT+cs+1, t)-PT-1;
            cout << PV[j] << "\n";
         }
         else{
            ll r = t-PT[cs], fl = r/cyt, lo = r%cyt;
            ll ans = PV[cs]+fl*cyw;
            ll j = upper_bound(PT+cs, PT+cs+cl+1, PT[cs]+lo)-PT-1;
            ans += PV[j]-PV[cs];
            cout << ans << "\n";
         }
      }
   }
   return 0;
}
