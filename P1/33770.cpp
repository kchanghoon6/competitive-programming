#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll T;
ll A[200000];  // 각 숫자의 개수
ll P[200000];  // 각 숫자의 페어 개수
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> T;
   while(T--){
      ll N;
      cin >> N;
      for(ll i=1; i<=N; i++){
         A[i] = 0;
      }
      for(ll i=0; i<N; i++){
         ll a;
         cin >> a;
         A[a]++;
      }
      ll ans = 1;
      ll cnt = 0;
      for(ll i=1; i<=N; i++){
         if(A[i] > 0){
            ans = cnt*2+1;
         }
         cnt += (A[i] >= 2);
      }
      cout << ans << "\n";
   }

   return 0;
}
