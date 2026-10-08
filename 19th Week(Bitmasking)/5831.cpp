#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, B;
ll k;
ll visited[100000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> N >> B;
   for(ll i=N-1; i>=0; i--){
      ll a;
      cin >> a;
      k = k | (a << i);
   }
   ll u = k;
   ll v = (k >> 1) | ((k & 1) << (N-1));
   ll cnt = 1;
   while(!visited[u]){
      visited[u] = cnt;
      u = u^v;
      v = (u >> 1) | ((u & 1) << (N-1));
      cnt++;
   }
   ll st = visited[u];
   ll len = cnt-st;
   if(B < st){
      u = k;
      v = (k >> 1) | ((k & 1) << (N-1));
      for(ll i=0; i<B; i++){
         u = u^v;
         v = (u >> 1) | ((u & 1) << (N-1));
      }
   }
   else{
      B = st + (B-st)%len;
      u = k;
      v = (k >> 1) | ((k & 1) << (N-1));
      for(ll i=0; i<B; i++){
         u = u^v;
         v = (u >> 1) | ((u & 1) << (N-1));
      }
   }
   for(ll i=N-1; i>=0; i--){
      cout << ((u >> i) & 1) << "\n";
   }

   return 0;
}
