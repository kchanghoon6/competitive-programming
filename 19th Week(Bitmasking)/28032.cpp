#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll C, N;
ll s[200000];
ll dist[300000];
queue<ll> q;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> C >> N;
   for(ll i=0; i<(1<<C); i++){
      dist[i] = -1;
   }
   for(ll i=0; i<N; i++){
      string str;
      cin >> str;
      ll mask = 0;
      for(ll j=C-1; j>=0; j--){
         if(str[j] == 'G'){
            mask |= (1 << j);
         }
      }
      s[i] = mask;
      dist[mask] = 0;
      q.push(mask);
   }
   for(ll i=0; i<N; i++){
      ll mask = (-s[i]-1) & ((1LL<<C)-1);
      cout << C-dist[mask] << "\n";
   }
   return 0;
}
