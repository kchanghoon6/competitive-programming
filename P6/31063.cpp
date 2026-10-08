#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, M;
ll A[200000];
ll B[200000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> N >> M;
   for(ll i=0; i<N; i++){
      cin >> A[i];
   }
   for(ll i=0; i<M; i++){
      cin >> B[i];
   }
   for(ll i=0; i<M; i++){
      ll k = 0;
      for(ll j=0; j<N; j++){
         if(k >= B[i])  break;
         if(k > A[j])  continue;
         ll d = 0;
         if(B[i] >= A[j]){
            d = A[j]-k;
         }
         else{
            d = B[i]-k;
         }
         A[j] += d;
         k += d;
      }
   }
   for(ll i=0; i<N; i++){
      cout << A[i] << "\n";
   }
   return 0;
}
