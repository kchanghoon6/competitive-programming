#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll const MOD = (ll)1e9 + 7;
ll N;
ll A[300000];
ll cnt[300000];
ll sum[300000];

void update_cnt(ll x, ll val){
   while(x <= 200000){
      cnt[x] += val;
      x += x & (-x);
   }
}
void update_sum(ll x, ll val){
   while(x <= 200000){
      sum[x] += val;
      x += x & (-x);
   }
}

ll cnt_(ll x){
   ll ret = 0;
   while(x > 0){
      ret += cnt[x];
      x -= x & (-x);
   }
   return ret;
}
ll sum_(ll x){
   ll ret = 0;
   while(x > 0){
      ret += sum[x];
      x -= x & (-x);
   }
   return ret;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   ll ans = 1;
   for(ll i=1; i<=N; i++){
      cin >> A[i];
      A[i]++;
      if(i==1){
         update_cnt(A[i], 1);
         update_sum(A[i], A[i]);
         continue;
      }
      ll uc = cnt_(A[i]-1);
      ll us = sum_(A[i]-1);
      ll r = ( (A[i] % MOD) * (uc % MOD) % MOD
      - (us % MOD) + MOD ) % MOD;
      ll oc = cnt_(200000) - cnt_(A[i]);
      ll os = sum_(200000) - sum_(A[i]);
      ll l = ( (os % MOD)
      - (A[i] % MOD) * (oc % MOD) % MOD + MOD ) % MOD;
      ll k = (l+r)%MOD;
      ans = ans * k%MOD;
      update_cnt(A[i], 1);
      update_sum(A[i], A[i]);
   }
   cout << ans%MOD<< "\n";
   return 0;
}
