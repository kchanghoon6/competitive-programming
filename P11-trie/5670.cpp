#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n;
ll vt[800001][27];
ll fin[800001];
ll sz = 1;
vector<string> A;


void insert_(string str){
   ll idx = 1;
   ll len = str.size();
   for(auto i : str){
      if(vt[idx][i-'a'] == 0){
         vt[idx][i-'a'] = ++sz;
      }
      idx = vt[idx][i-'a'];
   }
   fin[idx] = 1;
}
ll count_(string str){
   ll idx = 1;
   ll cnt = 1;
   ll first = 1;
   for(auto i : str){
      if(first){
         first = 0;
         idx = vt[idx][i-'a'];
         continue;
      }
      if(fin[idx]){
         cnt++;
         idx = vt[idx][i-'a'];
         continue;
      }
      for(ll j=0; j<26; j++){
         if(vt[idx][j] == vt[idx][i-'a']) continue;
         if(vt[idx][j]){
            cnt++;
            break;
         }
      }
      idx = vt[idx][i-'a'];
   }
   return cnt;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   while(cin >> n){
      for(ll i=1; i<=sz; i++){
         for(ll j=0; j<26; j++){
            vt[i][j] = 0;
         }
         fin[i] = 0;
      }
      sz = 1;
      A.clear();
      for(ll i=0; i<n; i++){
         string str;
         cin >> str;
         A.push_back(str);
         insert_(str);
      }
      double res = 0;
      for(ll i=0; i<n; i++){
         string str = A[i];
         res += count_(str);
      }
      cout << fixed;
      cout.precision(2);
      cout << res/A.size() << "\n";
   }


   return 0;
}
