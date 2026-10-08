#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

map<string, int> A;
set<string> B;
int N, F;
string str;

void add(string p, string P){
   if(!P.empty() && P[0] != P[1] && P[1] == P[2]){
      A[P]++;
   }
   if(!p.empty() && p[0] != p[1] && p[1] == p[2]){
      A[p]--;
   }
}
void check(string P){
   if(!P.empty() && P[0] != P[1] && P[1] == P[2] && A[P] >= F){
      B.insert(P);
   }
}
void remove(string p, string P){
   if(!P.empty() && P[0] != P[1] && P[1] == P[2]){
      A[P]--;
   }
   if(!p.empty() && p[0] != p[1] && p[1] == p[2]){
      A[p]++;
   }
}

void f(string x, string y, string z, string X, string Y, string Z){
   add(x, X);
   add(y, Y);
   add(z, Z);
   check(X);
   check(Y);
   check(Z);
   remove(x, X);
   remove(y, Y);
   remove(z, Z);
}
int main(){
   cin >> N >> F;
   cin >> str;

   for(int i=0; i<N-2; i++){
      string a = str.substr(i, 3);
      if(a[1] == a[2] && a[1] != a[0]){
         A[a]++;
      }
   }
   for(auto i : A){
      if(i.ss >= F){
         B.insert(i.ff);
      }
   }
   map<string, int> C;
   for(int i=0; i<N; i++){
      char e = str[i];
      for(int j=0; j<26; j++){
         if('a'+j == e) continue;
         string x, y, z, X, Y, Z;
         if(i >= 2){
            x = str.substr(i-2, 3);
         }
         if(i >= 1 && i<N-1){
            y = str.substr(i-1, 3);
         }
         if(i<N-2){
            z = str.substr(i, 3);
         }
         str[i] = 'a'+j;
         if(i >= 2){
            X = str.substr(i-2, 3);
         }
         if(i >= 1 && i<N-1){
            Y = str.substr(i-1, 3);
         }
         if(i<N-2){
            Z = str.substr(i, 3);
         }
         f(x, y, z, X, Y, Z);
         str[i] = e;
      }
   }

   cout << B.size() << "\n";
   for(auto i : B){
      cout << i << "\n";
   }
   return 0;
}
