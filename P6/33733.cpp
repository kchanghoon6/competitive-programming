#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;
ll P[2000000];
ll D[2000000];
ll C[2000000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   for(ll i=1; i<=N; i++){
      cin >> P[i];
      C[P[i]]++;
      D[i] = D[P[i]]+1;
   }
   for(ll i=1; i<=N; i++){
      if(C[i] == 0)  M++;
   }
   vector<ll> B(M);
   for(ll i=0; i<M; i++){
      cin >> B[i];
   }
   for(auto a : B){
      ll b = a;
      while(b && C[P[b]] == 1){
         b = P[b];
      }
      if(b) C[P[b]]--;
      cout << D[b] << "\n";
   }
   return 0;
}
