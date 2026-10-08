#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> A[20000];

ll N;

string f(ll p){
   string str;
   for(ll i=0; i<p; i++){
      str += "--";
   }
   return str;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N;
   for(ll i=0; i<N; i++){
      ll k;
      cin >> k;
      string str;
      for(ll j=1; j<=k; j++){
         cin >> str;
         A[i].push_back(str);
      }
   }
   sort(A, A+N);
   for(ll i=0; i<N; i++){
      ll p = 0;
      ll len2 = A[i].size();
      if(i != 0){
         ll len1 = A[i-1].size();
         for(ll j=0; j<len1 && j<len2; j++){
            if(A[i][j] == A[i-1][j])   p++;
            else  break;
         }
      }
      for(ll j=p; j<len2; j++)   cout << f(j) << A[i][j] << "\n";
   }


   return 0;
}
