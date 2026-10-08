#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<string> A;
map<string, ll> B;
int main(){
   string str;
   cin >> str;
   ll len = str.size();
   ll j=1;
   for(ll i=0; i<len; i++){
      for(ll j=2; i+j<=len; j++){
         A.insert(str.substr(i, j));
      }
   }
   A.insert(str);
   vector<string> P(A.begin(), A.end());
   sort(P.begin(), P.end(), [](const string a, const string b){
      if(a.size() != b.size())   return a.size() < b.size();
      return a < b;
   });
   for(auto i : P){
      B[i] = 1;
   }
   B[str] = 0;
   for(auto i : P){
      ll len = i.size();
      for(ll j=1; j<=len-1; j++){
         string c = i.substr(0, j);
         string a = c + i;
         string b = i + c;
         if(A.count(a)){
            B[a] += B[i];
            B[a] %= 2014;
         }
         if(A.count(b)){
            B[b] += B[i];
            B[b] %= 2014;
         }
      }
      for(ll j=1; j<=len-1; j++){
         string c = i.substr(j);
         string a = c + i;
         string b = i + c;
         if(A.count(a)){
            B[a] += B[i];
            B[a] %= 2014;
         }
         if(A.count(b)){
            B[b] += B[i];
            B[b] %= 2014;
         }
      }
   }
   cout << B[str]%2014 << "\n";

   return 0;
}
