#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll B, E;
ll s[200];
ll dist[100000];
string t;
ll T = 0;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> B >> E;
   cin >> t;
   for(ll i=0; i<B; i++){
      if(t[i] == '1'){
         T = T | (1LL << (B-1-i));
      }
   }
   queue<ll> q;
   for(ll i=0; i<(1<<B); i++){
      dist[i] = -1;
   }
   for(ll i=0; i<E; i++){
      string str;
      cin >> str;
      ll mask = 0;
      for(ll j=0; j<B; j++){
         if(str[j] == '1')   mask |= (1LL << (B-j-1));
      }
      s[i] = mask;
   }
   for(ll i=0; i<E; i++){
      for(ll j=0; j<E; j++){
         ll k = s[i] ^ s[j];
         if(dist[k] == -1){
            dist[k] = 1;
            q.push(k);
         }
      }
   }
   while(!q.empty()){
      ll v = q.front();
      q.pop();
      for(ll i=0; i<E; i++){
         ll k = s[i] ^ v;
         if(dist[k] == -1){
            dist[k] = dist[v] + 1;
            q.push(k);
         }
      }
   }
   if(dist[T] == -1){
      ll mini = 1e15;
      ll result = 0;
      for(ll i=0; i<(1<<B); i++){
         if(dist[i] != -1){
            ll diff = T ^ i;
            ll cnt = 0;
            while(diff){
               if(diff & 1LL) cnt++;
               diff >>= 1LL;
            }
            if(mini > cnt){
               mini = cnt;
               result = i;
            }
            else if(mini == cnt){
               if(dist[result] > dist[i]) result = i;
               else if(dist[result] == dist[i]){
                  if(result > i) result = i;
               }
            }
         }
      }
      cout << dist[result] << "\n";
      for(ll i=B-1; i>=0; i--){
         cout << ((result >> i) & 1);
      }
      cout << "\n";
   }
   else{
      cout << dist[T] << "\n";
      for(ll i=B-1; i>=0; i--){
         cout << ((T >> i) & 1);
      }
      cout << "\n";
   }
   return 0;
}
