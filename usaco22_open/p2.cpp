#include <bits/stdc++.h>
#define ll long long
#define pll pair<char, ll>
#define ff first
#define ss second
using namespace std;


ll N;
pll A[2000];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> N;

   for(ll i=0; i<N; i++){
      cin >> A[i].ff >> A[i].ss;
   }
   ll ans = 1e10;
   for(ll i=0; i<N; i++){
      ll x = A[i].ss;
      ll cnt = 0;
      for(ll j=0; j<N; j++){
         if(A[j].ff == 'L' && x > A[j].ss)   cnt++;
         if(A[j].ff == 'G' && x < A[j].ss)   cnt++;
      }
      ans = min(ans, cnt);
   }
   cout << ans << "\n";



   return 0;
}
