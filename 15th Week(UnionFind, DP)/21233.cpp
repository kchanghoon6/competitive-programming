#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K;
ll A[200000];
set<ll> B;
vector<ll> R;
vector<ll> C;
ll cnt = 0;
int main(){
   scanf("%lld %lld", &N, &K);
   for(ll i=0; i<N; i++){
      scanf("%lld", &A[i]);
   }
   for(ll i=0; i<N; i++){
      B.insert((A[i]-1)/12);
   }
   R.push_back(-1);
   for(auto i : B){
      R.push_back(i);
   }
   ll len = R.size();
   for(ll i=0; i<len-1; i++){
      C.push_back(R[i+1]-R[i]-1);
   }
   sort(C.begin(), C.end(), greater<ll>());
   for(ll i=K-1; i<C.size(); i++){
      cnt += C[i]*12;
   }
   cnt += (R.size()-1)*12;
   printf("%lld\n", cnt);
   return 0;
}
