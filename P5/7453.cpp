#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;


ll N;
ll A[5000][10];
vector<ll> B;
vector<ll> C;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);


   cin >> N;
   for(ll i=0; i<N; i++){
      for(ll j=0; j<4; j++){
         cin >> A[i][j];
      }
   }
   for(ll i=0; i<N; i++){
      for(ll j=0; j<N; j++){
         B.push_back(A[i][0]+A[j][1]);
      }
   }
   for(ll i=0; i<N; i++){
      for(ll j=0; j<N; j++){
         C.push_back(A[i][2]+A[j][3]);
      }
   }
   sort(B.begin(), B.end());
   sort(C.begin(), C.end());
   ll ans = 0;
   for(ll i=0; i<N*N; i++){
      ll k = B[i];
      auto lb = lower_bound(C.begin(), C.end(), -k);
      auto ub = upper_bound(C.begin(), C.end(), -k);
      ans += ub-lb;
   }

   cout << ans << "\n";


   return 0;
}
