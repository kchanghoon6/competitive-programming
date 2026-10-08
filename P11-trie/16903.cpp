#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m;
ll vt[8000000][5];
ll fin[8000000];
ll cnt[8000000];
ll sz = 1;

void insert_(ll a){
   ll idx = 1;
   for(ll i=31; i>=0; i--){
      ll k = (a>>i)&1LL;
      if(vt[idx][k] == 0)  vt[idx][k] = ++sz;
      idx = vt[idx][k];
      cnt[idx]++;
   }
}
void erase_(ll a){
   ll idx = 1;
   for(ll i=31; i>=0; i--){
      ll k = (a>>i)&1LL;
      if(vt[idx][k] == 0)  return;
      idx = vt[idx][k];
      cnt[idx]--;
   }
}
ll max_pair(ll a){
   ll idx = 1;
   ll res = 0;
   for(ll i=31; i>=0; i--){
      ll k = (a>>i)&1LL;
      ll p = 1-k;
      if(vt[idx][p] && cnt[vt[idx][p]] > 0){
         idx = vt[idx][p];
         res |= (1LL << i);
      }
      else{
         idx = vt[idx][k];
      }
   }
   return res;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> m;
   insert_(0);
   for(ll i=0; i<m; i++){
      ll a, b;
      cin >> a >> b;
      if(a == 1){
         insert_(b);
      }
      else if(a == 2){
         erase_(b);
      }
      else{
         cout << max_pair(b) << "\n";
      }
   }
   return 0;
}
