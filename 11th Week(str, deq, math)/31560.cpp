#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll A[500000];
ll B[500000];
int main(){
   ll N;
   scanf("%d", &N);
   for(ll i=0; i<N; i++){
      scanf("%lld", &A[i]);
   }
   // 증가하는 부분
   ll a = A[0];
   ll sum = 0;
   for(ll i=1; i<N; i++){
      a++;
      ll da = a-A[i];   // -1
      ll time = abs(da);
      sum += lev;

   }

   return 0;
}
