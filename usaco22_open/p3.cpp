#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, K;
ll A[200];
ll temp[200];
vector<ll> B[200];
ll f(ll num, ll cnt){
   if(temp[num] >= cnt){
      temp[num] -= cnt;
      return 1;
   }
   cnt -= temp[num];
   temp[num] = 0;
   if(B[num].size() == 0)  return 0;
   for(auto i : B[num]){
      if(!f(i, cnt)) return 0;
   }
   return 1;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N;
   for(ll i=1; i<=N; i++){
      cin >> A[i];
   }
   cin >> K;
   for(ll i=0; i<K; i++){
      ll L, M;
      cin >> L >> M;
      for(ll j=0; j<M; j++){
         ll a;
         cin >> a;
         B[L].push_back(a);
      }
   }
   ll s = 0, e = 1100000;
   ll res = 0;
   while(s <= e){
      ll mid = (s+e)/2;
      for(ll i=1; i<=N; i++) temp[i] = A[i];
      if(f(N, mid)){
         s = mid+1;
         res = mid;
      }
      else{
         e = mid-1;
      }
   }
   cout << res << "\n";


   return 0;
}
