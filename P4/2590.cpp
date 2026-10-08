#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[10];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   for(ll i=1; i<=6; i++){
      cin >> A[i];
   }
   ll ans = A[6];
   A[6] = 0;

   ans += A[5];
   ll num = A[5]*11;
   A[1] = max(A[1]-num, 0LL);
   A[5] = 0;

   ans += A[4];
   num = A[4]*5;
   ll k = A[2];
   A[2] = max(A[2]-num, 0LL);
   if(A[2] == 0){
      num -= k;
      num *= 4;
      A[1] = max(A[1]-num, 0LL);
   }
   ans += A[3]/4 + ((A[3]%4) ? 1 : 0);
   k = A[3]%4;
   if(k != 0){
      ll maxi;
      if(k == 1)  maxi = 5;
      else if(k == 2) maxi = 3;
      else  maxi = 1;
      ll l = min(A[2], maxi);
      A[2] -= l;
      ll rem = 36-k*9-l*4;
      A[1] = max(A[1]-rem, 0LL);
   }
   A[3] = 0;

   ans += A[2]/9 + ((A[2]%9) ? 1 : 0);
   k = A[2]%9;
   if(k != 0){
      ll rem = 36-k*4;
      A[1] = max(A[1]-rem, 0LL);
   }
   A[2] = 0;


   ans += A[1]/36 + ((A[1]%36) ? 1 : 0);
   A[1] = 0;

   cout << ans << "\n";
   return 0;
}
