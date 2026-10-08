#include <bits/stdc++.h>
using namespace std;

unordered_set<string> A[200];

int main(){
   cin.tie(0);
   cout.tie(0);
   int N;
   cin >> N;
   cin.ignore();
   for(int i=0; i<N; i++){
      string animal;
      cin >> animal;
      int n;
      cin >> n;
      for(int j=0; j<n; j++){
         string t;
         cin >> t;
         A[i].insert(t);
      }
   }
   int maxi = 0;
   for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
         int cnt = 0;
         for(auto t : A[j]){
            if(A[i].count(t)){
               cnt++;
            }
         }
         if(maxi < cnt) maxi = cnt;
      }
   }
   cout << (maxi + 1) << "\n";
   return 0;
}
