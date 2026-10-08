#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll n;
pll A[200000];
ll Y[200000];
pll B[200000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   for(ll i=0; i<n; i++){
      cin >> A[i].ff >> A[i].ss;
   }
   sort(A, A+n);
   ll g = 0;
   for(ll i=0; i<n; i++){
      Y[i] = A[i].ss;
   }
   ll mini = 1e15;
   ll maxi = -1e15;
   for(ll i=0; i<n; i++){
      B[i].ff = mini;
      mini = min(mini, Y[i]);
   }
   for(ll i=n-1; i>=0; i--){
      maxi = max(maxi, Y[i]);
      B[i].ss = maxi;
   }
   for(ll i=0; i<n; i++){
      if(B[i].ff > B[i].ss){
         g++;
      }
   }
   cout << g << "\n";


   return 0;
}
