#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, Q;
string S[300000];
ll LOR[300000];
ll ROR[300000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> Q;
   for(ll i=0; i<N; i++){
      cin >> S[i];
   }

   ll lf = -1;
   ll st = 0;
   ll mini = 1e15, maxi = 0;
   for(ll i=0; i<N; i++){
      if(lf == -1)   LOR[i] = 1;
      if(S[i] == "false"){
         lf = i;
      }
      if(S[i] == "or"){
         if(lf == -1){
            mini = min(mini, i-1);
            maxi = max(maxi, st);
         }
         for(ll j=max(st, lf); j<i; j++){
            ROR[j] = 1;
         }
         st = i+1;
         lf = -1;
      }
   }

   for(ll j=max(st, lf); j<N; j++){
      ROR[j] = 1;
   }
   if(lf == -1){
      mini = min(mini, N-1);
      maxi = max(maxi, st);
   }

   while(Q--){
      ll l, r;
      string str;
      cin >> l >> r >> str;
      l--; r--;
      if(str == "true" && ((LOR[l] == 1 && ROR[r] == 1) || mini < l || r < maxi)){
         cout << "Y";
      }
      else if(str == "false" && (l <= mini && maxi <= r)){
         cout << "Y";
      }
      else{
         cout << "N";
      }
   }
   cout << "\n";

   return 0;
}
