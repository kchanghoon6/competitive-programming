#include <bits/stdc++.h>
using namespace std;
int T;
int N[20], K[20];
string A[20];
int main(){
   cin >> T;
   for(int i=0; i<T; i++){
      cin >> N[i] >> K[i];
      cin >> A[i];
   }
   for(int i=0; i<T; i++){
      string B;
      for(int j=0; j<N[i]; j++){
         B += '.';
      }
      int cnt = 0;
      // G
      for(int j=0; j<N[i]; ){
         if(A[i][j] == 'G'){
            int idx = j + K[i];
            while(idx >= N[i])   idx--;
            B[idx] = 'G';
            j += 2*K[i]+1;
            cnt++;
         }
         else j++;
      }
      for(int j=0; j<N[i]; ){
         if(A[i][j] == 'H'){
            int idx = j + K[i];
            while(idx >= N[i] || B[idx] != '.')   idx--;
            B[idx] = 'H';
            j = idx + K[i] + 1;
            cnt++;
         }
         else j++;
      }
      cout << cnt << "\n";
      cout << B << "\n";
   }
   return 0;
}
