#include <bits/stdc++.h>
using namespace std;
int win[4][6];
int lie[4][6];
int lose[4][6];

int W[4][6];
int T[4][6];
int L[4][6];

int r;
bool found = false;

void f(int idx1, int idx2){
   if(found) return;
   if(idx1 == 5){
      for(int i=0; i<6; i++){
         if(win[r][i] != W[r][i] || lie[r][i] != T[r][i] || lose[r][i] != L[r][i])
            return;
      }
      found = true;
      return;
   }
   if(idx2 == 6){
      f(idx1 + 1, idx1 + 2);
      return;
   }
   win[r][idx1]++;
   lose[r][idx2]++;
   f(idx1, idx2+1);

   win[r][idx1]--;
   lose[r][idx2]--;
   lie[r][idx1]++;
   lie[r][idx2]++;
   f(idx1, idx2+1);

   lie[r][idx1]--;
   lie[r][idx2]--;
   win[r][idx2]++;
   lose[r][idx1]++;
   f(idx1, idx2+1);
   win[r][idx2]--;
   lose[r][idx1]--;
}
int main(){
   for(int i=0; i<4; i++){
      for(int j=0; j<6; j++){
         scanf("%d %d %d", &W[i][j], &T[i][j], &L[i][j]);
      }
   }

   for(int r=0; r<4; r++){
      for(int i=0; i<6; i++){
         win[r][i] = lie[r][i] = lose[r][i] = 0;
      }

      found = false;
      f(0, 1);
      printf("%d", found ? 1 : 0);
   }
   return 0;
}
