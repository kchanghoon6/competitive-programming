#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll t, n;
ll A[200000];
ll sum[200000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> t;
   while(t--){
      cin >> n;
      for(ll i=1; i<=n; i++){
         cin >> A[i];
         sum[i] = sum[i-1] + A[i];
      }
      vector<ll> B;
      ll s = sum[n];
      if(s == 0){
         cout << 0 << "\n";
         continue;
      }
      for(ll i=1; i*i<=s; i++){
         if(s%i == 0){
            B.push_back(i);
            if(i != s/i)   B.push_back(s/i);
         }
      }
      sort(B.rbegin(), B.rend());
      for(auto k : B){
         ll t = s/k;
         ll ans = 0;
         ll prev = 0;
         for(ll i=1; i<=n; i++){
            if((sum[i]-prev) == t){
               ans++;
               prev = sum[i];
            }
         }
         if(ans == k){
            cout << n-k << "\n";
            break;
         }
      }
   }


   return 0;
}
