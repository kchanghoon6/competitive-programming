#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
char A[300010];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N;
   for(ll i = 1; i <= N; i++){
      cin >> A[i];
   }
   ll cnt = 0;
   for(ll i=N; i>=1; i-=2){
      if(cnt%2==0){
         if(A[i-1]=='G' && A[i]=='H')  cnt++;
      }
      else{
         if(A[i-1]=='H' && A[i]=='G')  cnt++;
      }
   }
   cout << cnt << "\n";
   return 0;
}
