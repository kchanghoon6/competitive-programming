#include <bits/stdc++.h>
using namespace std;

string A[200];
vector<int> B[200];
int M[200];
int main(){
   int N;
   string a;
   cin >> N;
   for(int i=0; i<N; i++){
      cin >> A[i];
      cin >> M[i];
      cin >> a;
      int len_a = a.size();
      a = a.substr(1, len_a-2);
      for(auto c : a){
         if(c != ','){
            string t;
            t += c;
            B[i].push_back(stoi(t));
         }
      }
   }
   for(int i=0; i<N; i++){
      int len_A = A[i].size();
      int s = 0;
      int e = B[i].size()-1;
      bool rev = false;
      bool flag = true;
      for(int j=0; j<len_A; j++){
         if(A[i][j] == 'R'){
            rev = !rev;
         }
         else{
            if(s > e){
               cout << "error\n";
               flag = false;
               break;
            }
            if(rev) e--;
            else  s++;
         }
      }
      if(flag){
         cout << "[";
         if(rev){
            for(int j=e; j>=s; j--){
               cout << B[i][j];
               if(j != s)  cout << ",";
            }
            cout << "]\n";
         }
         else{
            for(int j=s; j<=e; j++){
               cout << B[i][j];
               if(j != e)  cout << ",";
            }
            cout << "]\n";
         }
      }
   }
   return 0;
}
