#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll T, N;
ll A[1000000];
ll sum[1000000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> T;
   while(T--){
      cin >> N;

      for(ll i=1; i<=N; i++){
         cin >> A[i];
      }
      sum[1] = A[1];
      for(ll i=2; i<=N; i++){
         sum[i] = (sum[i-1]+A[i]);
      }
      ll mini = 1e15;
      for(ll L=0; L<=N/2-1; L++){
         ll k = sum[L+N/2+1]-sum[L];
         mini = min(mini, k);
      }
      cout << mini << " " << sum[N]-mini << "\n";

      for(ll i=1; i<=N; i++){
         A[i] = 0;
         sum[i] = 0;
      }
   }

   return 0;
}
