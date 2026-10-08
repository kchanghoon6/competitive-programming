#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll A[200000];
ll tree[200000];

void update_(ll x, ll val){
   while(x <= N){
      tree[x] += val;
      x += x & (-x);
   }
}
ll sum_(ll x){
   ll ret = 0;
   while(x > 0){
      ret += tree[x];
      x -= x & (-x);
   }
   return ret;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   for(ll i=1; i<=N; i++){
      cin >> A[i];
      update_(i, A[i]);
   }
   for(ll i=2; i<=N; i++){
      ll k = i & (-i);
      if(k == 1)  continue;
      ll r = sum_(i-1);
      ll l = sum_(i-k);
      ll diff = r-l;
      if(diff != 0){
         update_(i-1, -diff);
         A[i-1] -= diff;
      }
   }
   for(ll i=1; i<=N; i++){
      cout << A[i] << " ";
   }
   cout << "\n";


   return 0;
}
