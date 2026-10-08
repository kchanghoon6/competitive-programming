#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> A[50];
ll B[50][20]; // 7 * 7(7로 나눈 나머지)
ll C[50];
ll cnt;


void backtrack(int d){
   if(d == 7){
      ll bessie = C[0]+2*C[1]+2*C[2]+C[3];
      ll goes = C[4]+C[5]+C[1]+C[2];
      ll moo = C[6] + 2*C[5];
      if(bessie%7==0 || goes%7==0 || moo%7==0){
         ll ways = 1;
         for(int i=0; i<7; i++){
            ways *= B[i][C[i]];
         }
         cnt += ways;
      }
      return;
   }
   for(int i=0; i<7; i++){
      C[d] = i;
      backtrack(d+1);
   }
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
      for(ll x : A[i]){
         B[i][(x%7+7)%7]++;
      }
   }
   backtrack(0);
   cout << cnt << "\n";

   return 0;
}
