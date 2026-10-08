#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll c[2000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   for(ll i=0; i<N; i++){
      cin >> c[i];
   }
   ll e = 0;
   for(ll i=0; i<N; i++){
      while(c[i] > 1){
         for(ll j=1; j<N; j++){
            ll idx = (i + j) % N;
            if(c[idx] == 0){
               c[idx]++;
               c[i]--;
               e += j * j;
               break;
            }
         }
      }
   }
   cout << e << "\n";

   return 0;
}
