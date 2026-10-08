// #include <bits/stdc++.h>
// using namespace std;
// with stack
/*
stack<char> s;
string a;
string b;

int main(){
   cin >> a;
   cin >> b;

   int len_a = a.size();
   int len_b = b.size();
   for(int i=0; i<len_a; i++){
      int idx = len_b-1;
      s.push(a[i]);
      while(!s.empty() && s.top() == b[idx] && idx >= 0){
         s.pop();
         idx--;
      }
      if(idx != -1){
         while(idx+1 <= len_b-1){
            idx++;
            s.push(b[idx]);
         }
      }
   }
   string output;
   while(!s.empty()){
      output = s.top() + output;
      s.pop();
   }
   cout << output << "\n";
   return 0;
}
*/
// with string only
#include <bits/stdc++.h>
using namespace std;
string A;
string B;
string C;
int main(){
   cin >> A;
   cin >> B;

   int len_A = A.size();
   int len_B = B.size();
   for(int i=0; i<len_A; i++){
      C += A[i];
      int len_C = C.size();
      if(len_C >= len_B){
         if(C.substr(len_C-len_B) == B){
            for(int j=0; j<len_B; j++){
               C.pop_back();
            }
         }
      }
   }
   cout << C << "\n";
}
