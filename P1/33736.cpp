#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll A[300000];
ll B[300000];     // 0 개수 누적
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   for(ll i=0; i<N; i++){
      ll k;
      cin >> k;
      A[k]++;
   }
   ll a = 0;
   for(ll i=0; i<=N; i++){
      B[i] = a;
      a += (A[i] == 0) ? 1 : 0;
   }

   for(ll i=0; i<=N; i++){
      if(A[i] != 0){
         cout << max(A[i], B[i]) << "\n";
      }
      else{
         cout << B[i] << "\n";
      }
   }
   return 0;
}
