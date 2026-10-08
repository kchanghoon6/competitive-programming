#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T;
ll H[200000];
ll P[200000];
ll visited[200000];

void solve(){
   ll N;
   cin >> N;
   for(ll i=1; i<=N; i++){
      visited[i] = 0;
      P[i] = 0;
      H[i] = 0;
   }
   for(ll i=1; i<=N-1; i++){
      cin >> H[i];
      visited[H[i]] = 1;
   }
   if(H[N-1] != 1){
      cout << "-1\n";
      return;
   }
   vector<ll> v;
   for(ll i=1; i<=N; i++){
      if(!visited[i]){
         v.push_back(i);
      }
   }
   if(v.size() == 1){
      ll a = v[0];
      P[1] = 1;
      P[N] = a;
      for(ll i=N-1; i>1; i--){
         P[i] = H[N-i];
      }
   }
   else if(v.size() == 2){
      ll x = count(H+1, H+N, 1);
      if(x != 2){
         cout << "-1\n";
         return;
      }
      ll a = v[0], b = v[1];
      P[1] = min(a, b);
      P[N] = max(a, b);
      ll lidx = 1, ridx = N;
      for(ll i=1; i<=N-2; i++){
         if(P[lidx] < P[ridx]){
            P[--ridx] = H[i];
         }
         else{
            P[++lidx] = H[i];
         }
      }
   }
   else{
      cout << -1 << "\n";
      return;
   }
   for(ll i=1; i<=N; i++){
      cout << P[i] << " ";
   }
   cout << "\n";
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> T;
   while(T--){
      solve();
   }

   return 0;
}
