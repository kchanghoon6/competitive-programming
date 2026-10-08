#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, M, K;
ll A[2000000];
ll tree[2000000];

void update_(ll i, ll val){
   while(i <= N){
      tree[i] += val;
      i += (i&(-i));
   }
}
ll sum_(ll i){
   ll ret = 0;
   while(i > 0){
      ret += tree[i];
      i -= (i&(-i));
   }
   return ret;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> M >> K;
   for(ll i=1; i<=N; i++){
      cin >> A[i];
      update_(i, A[i]);
   }
   for(ll i=1; i<=M+K; i++){
      ll a, b, c;
      cin >> a >> b >> c;
      if(a == 1){
         update_(b, c-A[b]);
         A[b] = c;
      }
      else{
         cout << sum_(c)-sum_(b-1)<< "\n";
      }
   }

   return 0;
}
