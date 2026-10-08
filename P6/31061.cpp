#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K;
ll A[600000];
ll B[600000];
ll P[600000];
ll Q[600000];
ll cnt1[600000];
ll cnt2[600000];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> N >> K;
   for(ll i=1; i<=K; i++)   cin >> A[i];
   for(ll i=1; i<=K; i++)   cin >> B[i];

   for(ll i=1; i<=K; i++){
      P[A[i]] = i;
      Q[B[i]] = i;
   }
   ll up = 0;
   for(ll i=1; i<=N; i++){
      if(P[i] == 0 && Q[i] == 0){
         up++;
         continue;
      }
      else if(P[i] == 0 || Q[i] == 0)  continue;
      ll d1 = (P[i]-Q[i]+K)%K;
      cnt1[d1]++;
      ll d2 = (P[i]+Q[i])%K;
      cnt2[d2]++;
   }
   ll maxi = 0;
   for(ll i=0; i<=K; i++){
      maxi = max(cnt1[i], maxi);
      maxi = max(cnt2[i], maxi);
   }
   cout << maxi + up << "\n";
   return 0;
}
