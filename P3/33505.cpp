#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;



ll T;
ll A[600000];

void f(vector<pll>& B, ll x, ll m){
   ll h = m/2;
   ll a = 0;
   if(m%2 == 0){
      a = (x < h) ? -1 : 1;
      B.push_back({a, 0});
      B.push_back({-2, (x+h)%m});
      B.push_back({2, x});
   }
   else{
      a = ((x < h) ? -1 : (x == h) ? 0 : 1);
      B.push_back({a, 0});
      B.push_back({2, x});
      B.push_back({-1, (x+h)%m});
      B.push_back({-1, (x+h+1)%m});
   }
}



int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> T;
   while(T--){
      ll N, M;
      cin >> N >> M;
      for(ll i=1; i<=N; i++){
         cin >> A[i];
         A[i] %= M;
      }
      sort(A+1, A+N+1);

      vector<pll> B;
      for(ll i=1; i<=N; i++){
         f(B, A[i], M);
      }
      sort(B.begin(), B.end(), [](const pll &a, const pll &b){
         if(a.ss == b.ss) return a.ff < b.ff;
         return a.ss < b.ss;
      });

      ll a = 0, s = 0, t = 0;
      for(ll i=1; i<=N; i++){
         s += min(A[i], M-A[i]);
      }
      ll ans = s;
      ll x = 0;
      for(auto i : B){
         s += a*(i.ss-x);
         x = i.ss;
         a += i.ff;
         ans = min(ans, s);
      }
      cout << ans << "\n";
   }



   return 0;
}
