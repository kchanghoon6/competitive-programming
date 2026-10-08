#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N;
ll A[100010];
ll vt[3000010][3];
ll fin[3000010];
ll sz = 1;
vector<ll> B;

void insert_(ll a){
   ll idx = 1;
   for(ll i=31; i>=0; i--){
      ll k = (a>>i)&1LL;
      if(vt[idx][k] == 0)  vt[idx][k] = ++sz;
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
            res = res|(1<<i);
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
            res = res|(1<<i);
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
   cin >> N;

   for(ll i=0; i<N; i++){
      cin >> A[i];
      insert_(A[i]);
   }
   for(ll i=0; i<N; i++){
      B.push_back(max_pair(A[i]));
   }
   sort(B.begin(), B.end());
   cout << B[B.size()-1] << "\n";





   return 0;
}
