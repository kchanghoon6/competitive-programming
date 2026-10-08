#include <bits/stdc++.h>
using namespace std;
vector<int> A[100];
int B[100][10]; // 각 알파벳의 홀짝 개수
int C[10];
int cnt;
// BESIGOM
void backtrack(int d){
   if(d == 7){
      int bessie = C[0]+2*C[1]+2*C[2]+C[3];
      int goes = C[4]+C[5]+C[1]+C[2];
      int moo = C[6] + 2*C[5];
      if(bessie%2==0 || goes%2==0 || moo%2==0){
         int ways = 1;
         for(int i=0; i<7; i++){
            ways *= B[i][C[i]];
         }
         cnt += ways;
      }
      return;
   }
   C[d] = 0;
   backtrack(d+1);
   C[d] = 1;
   backtrack(d+1);
}

int main(){
   int N;
   cin >> N;
   for(int i=0; i<N; i++){
      char a;
      int b;
      cin >> a >> b;
      int idx;
      if(a == 'B')   idx = 0;
      if(a == 'E')   idx = 1;
      if(a == 'S')   idx = 2;
      if(a == 'I')   idx = 3;
      if(a == 'G')   idx = 4;
      if(a == 'O')   idx = 5;
      if(a == 'M')   idx = 6;
      A[idx].push_back(b);
   }
   for(int i=0; i<7; i++){
      for(int x : A[i]){
         if(x%2 == 0)   B[i][0]++;
         else  B[i][1]++;
      }
   }
   backtrack(0);
   cout << cnt << "\n";
   return 0;
}
