#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N;
ll A[400][400];
ll X[400];
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   for(ll i=1; i<=N; i++){
      for(ll j=i; j<=N; j++){
         cin >> A[i][j];
      }
   }
   X[N] = 0;
   X[N-1] = A[N-1][N];
   for(ll i=N-2; i>=1; i--){
      X[i] = X[i+1]+A[i][i+1];
      ll maxi = -1e15, mini = 1e15;
      for(ll j=i; j<=N; j++){
         maxi = max(maxi, X[j]);
         mini = min(mini, X[j]);
         ll diff = maxi-mini;
         if(diff != A[i][j]){
            X[i] = X[i+1]-A[i][i+1];
            break;
         }
      }
   }
   for(ll i=1; i<=N; i++){
      cout << X[i] << " ";
   }
   cout << "\n";
   return 0;
}
