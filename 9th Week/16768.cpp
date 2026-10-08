#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[200][20];  // 100 10
bool visited[200][20];
int X[4] = {1, -1, 0 , 0};
int Y[4] = {0 , 0, 1, -1};
bool flag;

void f(void){
   flag = false;
   for(int i=0; i<N; i++){
      for(int j=0; j<10; j++){
         queue<pair <int, int>> q;
         vector<pair <int, int>> t;
         if(!visited[i][j] && A[i][j] != 0){
            t.push_back(make_pair(i, j));
            q.push(make_pair(i, j));
            visited[i][j] = true;
            int c = 1;
            while(!q.empty()){
               pair<int, int> v = q.front();
               q.pop();
               for(int dir=0; dir<4; dir++){
                  int nx = v.first + X[dir];
                  int ny = v.second + Y[dir];
                  if(nx<N && nx>=0 && ny<10 && ny>=0 && !visited[nx][ny] && A[i][j] == A[nx][ny]){
                     visited[nx][ny] = true;
                     q.push(make_pair(nx, ny));
                     t.push_back(make_pair(nx, ny));
                     c++;
                  }
               }
            }
            int len = t.size();
            if(c >= K){
               flag = true;
               for(int s=0; s<len; s++){
                  A[t[s].first][t[s].second] = 0;
               }
               t.clear();
            }
         }
      }
   }
   for(int j=0; j<10; j++){
      for(int i=N-1; i>=0; i--){
         visited[i][j] = false;
         for(int k=i+1; k<N; k++){
            if(A[k][j] == 0){
               A[k][j] = A[k-1][j];
               A[k-1][j] = 0;
            }
         }
      }
   }
   if(flag) f();
   else return;
}

int main(){
   scanf("%d %d", &N, &K);
   for(int i=0; i<N; i++){
      for(int j=0; j<10; j++){
         scanf("%1d", &A[i][j]);
      }
   }
   f();
   for(int i=0; i<N; i++){
      for(int j=0; j<10; j++){
         printf("%d", A[i][j]);
      }
      printf("\n");
   }
}
