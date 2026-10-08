#include <bits/stdc++.h>
#define ll long long
using namespace std;



ll N;
ll A[200000];
ll tree[200000];
ll last[200000];

void update_(ll x, ll val){
   while(x <= 110000){
      tree[x] += val;
      x += (x&(-x));
   }
}
ll sum_(ll x){
   ll ret = 0;
   while(x > 0){
      ret += tree[x];
      x -= (x&(-x));
   }
   return ret;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   ll prev = 0;
   for(ll i=0; i<N; i++){
      ll l, r;
      cin >> l >> r;
      cout << (sum_(l) - last[l]) + (sum_(r) - last[r]) << "\n";
      last[l] = sum_(l);
      last[r] = sum_(r);
      if(l+1 <= r-1){
         update_(l+1 , 1);
         update_(r, -1);
      }
   }


   return 0;
}
