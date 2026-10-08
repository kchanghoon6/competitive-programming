#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll visited[20];
set<char> A[20];

ll f(string str, ll idx){
   if(idx == str.size())   return 1;
   for(ll i=0; i<4; i++){
      if(!visited[i] && A[i].find(str[idx]) != A[i].end()){
         visited[i] = 1;
         if(f(str, idx+1)) return 1;
         visited[i] = 0;
      }
   }
   return 0;
}



int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   ll n;
   cin >> n;
   for(ll i=0; i<4; i++){
      for(ll j=0; j<6; j++){
         char a;
         cin >> a;
         A[i].insert(a);
      }
   }
   for(ll i=0; i<n; i++){
      string str;
      cin >> str;
      for(ll j=0; j<4; j++){
         visited[j] = 0;
      }
      cout << (f(str, 0) ? "YES" : "NO") << "\n";
   }




   return 0;
}
