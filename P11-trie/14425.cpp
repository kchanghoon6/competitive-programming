#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, M;
ll sz = 1;
ll fin[5000005];
ll vt[5000005][27];

void insert(string str){
   ll idx = 1;
   for(auto i : str){
      if(vt[idx][i-'a'] == 0){
         vt[idx][i-'a'] = ++sz;
      }
      idx = vt[idx][i-'a'];
   }
   fin[idx] = 1;
}
ll find_(string str){
   ll idx = 1;
   for(auto i : str){
      if(vt[idx][i-'a'] == 0) return 0;
      idx = vt[idx][i-'a'];
   }
   return fin[idx];
}
void erase(string str){
   ll idx = 1;
   for(auto i : str){
      if(vt[idx][i-'a'] == 0) return;
      idx = vt[idx][i-'a'];
   }
   fin[idx] = 0;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);


   cin >> N >> M;
   for(ll i=0; i<N; i++){
      string str;
      cin >> str;
      insert(str);
   }
   ll ans = 0;
   for(ll i=0; i<M; i++){
      string str;
      cin >> str;
      ans += find_(str);
   }
   cout << ans << "\n";


   return 0;
}
