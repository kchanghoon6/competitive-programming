#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll P, NS, T;
ll A[500000];
vector<ll> B;
int main(){
   scanf("%lld %lld %lld", &P, &NS, &T); //passage num splitnum arrival
   for(ll i=0; i<NS; i++){
      ll a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      A[b] = a;
      A[c] = a;
   }
   ll j = A[T];
   B.push_back(T);
   ll cnt = 0;
   while(j != 1){
      B.push_back(j);
      j = A[j];
      cnt++;
   }
   B.push_back(1);
   printf("%lld\n", cnt+2);
   for(ll i=B.size()-1; i>=0; i--){
      printf("%lld\n", B[i]);
   }
   return 0;
}
