#include <bits/stdc++.h>
using namespace std;
int N;
int X[500];    // 200
int Y[500];    // 200
int P[500];    // 200
vector<int> lis[500];
bool ch[500];
int c_max;
int c = 1;

void DFS(int v){
   ch[v] = true;
   c_max = max(c_max, c);
   for(int i=0; i<lis[v].size(); i++){
      if(!ch[lis[v][i]]){
         c++;
         DFS(lis[v][i]);
      }
   }
   return;
}

int main(){
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      scanf("%d %d %d", &X[i], &Y[i], &P[i]);
   }

   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         int x = abs(X[j]-X[i]);
         int y = abs(Y[j]-Y[i]);
         int z = x*x + y*y;
         if(z <= P[i]*P[i] && z != 0){
            lis[i].push_back(j);
         }
      }
   }
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         ch[j] = false;
      }
      c = 1;
      DFS(i);
   }
   printf("%d\n", c_max);
}
