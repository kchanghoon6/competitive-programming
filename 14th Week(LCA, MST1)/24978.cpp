#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
vector<ll> S[50][50];
vector<ll> T[50][50];
string Q[200000];
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   string s, t;
   cin >> s;
   cin >> t;
   cin >> N;

   for(ll i=0; i<N; i++){
      cin >> Q[i];
   }
   for(ll i=0; i<18; i++){
      for(ll j=0; j<18; j++){
         if(i == j)  continue;
         char c = 'a'+i;
         char d = 'a'+j;
         for(auto k : s){
            if(k == c){
               S[c-'a'][d-'a'].push_back(1);
            }
            else if(k == d){
               S[c-'a'][d-'a'].push_back(2);
            }
         }
         for(auto k : t){
            if(k == c){
               T[c-'a'][d-'a'].push_back(1);
            }
            else if(k == d){
               T[c-'a'][d-'a'].push_back(2);
            }
         }
      }
   }
   for(ll i=0; i<N; i++){
      string str = Q[i];
      bool flag = 0;
      for(auto j : str){
         for(auto k : str){
            if(j == k)  continue;
            if((S[j-'a'][k-'a'] != 0 || T[j-'a'][k-'a'] != 0) && S[j-'a'][k-'a'] != T[j-'a'][k-'a']){
               cout << "N";
               flag = 1;
               break;
            }
         }
         if(flag) break;
      }
      if(!flag){
         cout << "Y";
      }
   }
   return 0;
}
