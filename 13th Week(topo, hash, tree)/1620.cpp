#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> A;
map<int, string> B;
int main(){
   cin.tie(0);
   cout.tie(0);
   cin >> N >> M;
   for(int i=0; i<N; i++){
      string a;
      cin >> a;
      A[a] = i+1;
      B[i+1] = a;
   }
   for(int i=0; i<M; i++){
      string a;
      cin >> a;
      if(a[0] >= '0' && a[0] <= '9'){
         cout << B[stoi(a)] << "\n";
      }
      else{
         cout << A[a] << "\n";
      }
   }


   return 0;
}
