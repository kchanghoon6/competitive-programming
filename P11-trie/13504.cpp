#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T;
ll P[1000010];
ll vt[3500000][5];
ll fin[3500000];
ll sz = 1;

void insert_(ll a){
   ll idx = 1;
   for(ll i=31; i>=0; i--){
      ll k = (a>>i)&1LL;
      if(vt[idx][k]==0)  vt[idx][k] = ++sz;
      idx = vt[idx][k];
   }
   fin[idx] = 1;
}
ll max_pair(ll a){
   ll idx = 1;
   ll res = 0;
   for(ll i=31; i>=0; i--){
      ll k = (a>>i)&1LL;
      if(k){
         if(vt[idx][0]){
            idx = vt[idx][0];
            res = res|(1LL<<i);
         }
         else if(vt[idx][1]){
            idx = vt[idx][1];
         }
         else{
            if(fin[idx])   return res;
            else  return 0;
         }
      }
      else{
         if(vt[idx][1]){
            idx = vt[idx][1];
            res = res|(1LL<<i);
         }
         else if(vt[idx][0]){
            idx = vt[idx][0];
         }
         else{
            if(fin[idx])   return res;
            else  return 0;
         }
      }
   }
   return res;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> T;
   while(T--){
      ll n;
      cin >> n;
      for(ll i=0; i<=sz; i++){
         vt[i][0] = 0, vt[i][1] = 0;
         fin[i] = 0;
      }
      sz = 1;
      P[0] = 0;
      insert_(P[0]);
      for(ll i=1; i<=n; i++){
         ll a;
         cin >> a;
         P[i] = P[i-1]^a;
         insert_(P[i]);
      }
      ll ans = 0;
      for(ll i=1; i<n; i++){
         ans = max(ans, max_pair(P[i]));
      }
      cout << ans << "\n";
   }



   return 0;
}
