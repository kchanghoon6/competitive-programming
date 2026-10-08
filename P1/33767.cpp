// 위상정렬해서 하면 됨
#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

ll N, A, B;
map<ll, ll> cnt;    // (di, ni)
map<ll, ll> cnt2;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> A >> B;
   for(ll i=0; i<N; i++){
      ll d, n;
      cin >> n >> d;
      cnt[d] = n;
      cnt2[d] = n;
   }
   ll ans = 0;
   ll maxi = 0;
   for(auto &i : cnt){
      if(2*i.ff == A || 2*i.ff == B){
         ans += i.ss/2;
         cnt[i.ff] -= i.ss;
         continue;
      }
      if(cnt.find(A-i.ff) != cnt.end()){
         ll mini = min(i.ss, cnt[A-i.ff]);
         ans += mini;
         cnt[i.ff] -= mini;
         cnt[A-i.ff] -= mini;
      }
      if(cnt.find(B-i.ff) != cnt.end()){
         ll mini = min(i.ss, cnt[B-i.ff]);
         ans += mini;
         cnt[i.ff] -= mini;
         cnt[B-i.ff] -= mini;
      }
   }
   maxi = ans;
   ans = 0;
   for(auto &i : cnt2){
      if(2*i.ff == A || 2*i.ff == B){
         ans += i.ss/2;
         cnt2[i.ff] -= i.ss;
         continue;
      }
      if(cnt2.find(B-i.ff) != cnt2.end()){
         ll mini = min(i.ss, cnt2[B-i.ff]);
         ans += mini;
         cnt2[i.ff] -= mini;
         cnt2[B-i.ff] -= mini;
      }
      if(cnt2.find(A-i.ff) != cnt2.end()){
         ll mini = min(i.ss, cnt2[A-i.ff]);
         ans += mini;
         cnt2[i.ff] -= mini;
         cnt2[A-i.ff] -= mini;
      }
   }
   maxi = max(ans, maxi);
   cout << maxi << "\n";


   return 0;
}
