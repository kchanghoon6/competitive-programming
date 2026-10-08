#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s, t;
vector<ll> A[200];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> s >> t;

   ll slen = s.size();
   ll tlen = t.size();

   for(ll i=0; i<tlen; i++){
      A[t[i]-'a'].push_back(i);
   }
   ll prev = -1;
   ll n = 1;
   for(ll i=0; i<slen; i++){
      char c = s[i];
      if(A[c-'a'].empty()){
         n = -1;
         break;
      }
      auto iter = upper_bound(A[c-'a'].begin(), A[c-'a'].end(), prev);
      if(iter == A[c-'a'].end()){
         prev = -1;
         iter = upper_bound(A[c-'a'].begin(), A[c-'a'].end(), prev);
         n++;
      }
      prev = *iter;
   }
   cout << n << "\n";
   return 0;
}
