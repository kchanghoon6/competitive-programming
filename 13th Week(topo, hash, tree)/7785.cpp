#include <bits/stdc++.h>
using namespace std;
unordered_set<string> A;
vector<string> B;
int main(){
   int N;
   cin >> N;

   for(int i=0; i<N; i++){
      string a, b;
      cin >> a >> b;
      if(b == "enter"){
         A.insert(a);
      }
      else{
         A.erase(a);
      }
   }
   for(auto i : A){
      B.push_back(i);
   }
   sort(B.begin(), B.end());
   for(int i=B.size()-1; i>=0; i--){
      cout << B[i] << "\n";
   }
   return 0;
}
