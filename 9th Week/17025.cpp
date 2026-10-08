#include <bits/stdc++.h>
using namespace std;
int N;
char A[2000][2000];   // 1000 1000
bool visited[2000][2000];
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
vector<pair<int, int>> cp;
int c = 1;
int p = 0;

void DFS(int t, int s){
   visited[t][s] = true;
   for(int dir=0; dir<4; dir++){
      int nx = t + X[dir];
      int ny = s + Y[dir];
      if(nx < N && nx > -1 && ny < N && ny > -1 ){
         if(A[nx][ny] == '#' && !visited[nx][ny]){
            c++;
            DFS(nx, ny);
         }
         else if(A[nx][ny] == '.'){
            p++;
         }
      }
      else{
         p++;
      }
   }
   return;
}

int main(){
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      scanf("%s", A[i]);
   }

   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         if(A[i][j] == '#' && !visited[i][j]){
            DFS(i, j);
            cp.push_back(make_pair(c, p));
            c = 1;
            p = 0;
         }
      }
   }
   sort(cp.begin(), cp.end(), [](auto &a, auto &b){
      if(a.first == b.first) return a.second < b.second;
      return a.first > b.first;
   });
   printf("%d %d\n", cp[0].first, cp[0].second);
}
