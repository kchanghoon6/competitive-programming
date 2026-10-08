#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


ll N, M, A;
int main(){
   scanf("%lld %lld %lld", &N, &M, &A);
   ll result = 1;
   for(ll i=1; i<N; i++){
      result *= M;
      result %= mod;
   }
   printf("%lld\n", result);
   return 0;
}
