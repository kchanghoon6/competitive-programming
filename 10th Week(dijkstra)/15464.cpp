#include <bits/stdc++.h>
using namespace std;

int N;
int A[1000];
string ID[1000];
string new_ID[1000];

int main(){
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      cin >> A[i];
   }
   for(int i=0; i<N; i++){
      cin >> ID[i];
   }
   int m=3;
   for(int i=0; i<m; i++){
      for(int j=0; j<N; j++){
         new_ID[j] = ID[A[j]-1];
      }
      for(int j=0; j<N; j++){
         ID[j] = new_ID[j];
      }
   }
   for(int i=0; i<N; i++){
      cout << ID[i] << "\n";
   }
   return 0;
}
