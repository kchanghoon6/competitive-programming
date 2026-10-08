#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<ll> A;
map<ll, ll> D;
ll sum;
ll k;

int main(){
   ll N;
   scanf("%lld", &N);
   scanf("%lld", &k);
   A.insert(k);
   D[k] = 1;
   sum += 1;
   for(ll i=1; i<N; i++){
      ll a;
      scanf("%lld", &a);
      auto it = A.lower_bound(a);
      ll maxi = 1;
      if(it != A.begin()){
         maxi = max(D[*prev(it)], (it != A.end()) ? D[*it] : 0) + 1;
      }
      else{
         maxi = D[*it] + 1;
      }
      A.insert(a);
      D[a] = maxi;
      sum += maxi;
   }
   printf("%lld\n", sum);
   return 0;
}
