#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll tree[200000];
ll A[200000];
ll B[200000];
ll inv[200000];

void update_(ll x, ll val){
   while(x <= 100000){
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
      A[i]++;
      inv[i] = i-1-sum_(A[i]);
      update_(A[i], 1);
      B[i] = i;
   }

   sort(B+1, B+N+1, [](ll a, ll b){return A[a] < A[b];});

   ll ans = 0;
   ll j = 1;
   cout << ans << "\n";
   for(ll i=1; i<N; i++){
      while(j < N && A[B[j]] <= i){
         ans += inv[B[j]];
         j++;
      }
      cout << ans << "\n";
   }

   return 0;
}
