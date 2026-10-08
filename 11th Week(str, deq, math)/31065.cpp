#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll T, N;
vector<pair<ll, pll>> A(300000);  //t,  a(slope), h(inital height)
ll B[300000];
int main(){
   scanf("%lld", &T);
   while(T--){
      scanf("%lld", &N);
      for(ll i=0; i<N; i++){
         scanf("%lld", &A[i].ss.ss);
      }
      for(ll i=0; i<N; i++){
         scanf("%lld", &A[i].ss.ff);
      }
      for(ll i=0; i<N; i++){
         scanf("%lld", &A[i].ff);
      }
      sort(A.begin(), A.begin()+N);
      ll maxi = 0;
      bool flag = 0;
      for(ll i=0; i<N-1; i++){
         ll h1 = A[i+1].ss.ss;
         ll h = A[i].ss.ss;
         ll a1 = A[i+1].ss.ff;
         ll a = A[i].ss.ff;
         if(h1-h >= 0 && a-a1 <= 0){
            flag = 1;
            break;
         }
         if(h1-h < 0)   continue;
         maxi = max(maxi, (h1-h)/(a-a1)+1);
      }
      if(!flag){
         for(ll i=0; i<N; i++){
            B[i] = A[i].ss.ss + A[i].ss.ff*maxi;
         }
         for(ll i=0; i<N-1; i++){
            if(B[i] <= B[i+1]){
               flag = 1;
               break;
            }
         }
      }
      if(!flag) printf("%lld\n", maxi);
      else  printf("-1\n");
      for(ll i=0; i<N; i++){
         A[i].ff = 0;
         A[i].ss.ff = 0;
         A[i].ss.ss = 0;
         B[i] = 0;
      }
   }
   return 0;
}
