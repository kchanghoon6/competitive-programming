#include <bits/stdc++.h>
using namespace std;

int X[4] = {1, -1, 0 , 0};
int Y[4] = {0 , 0, 1, -1};
char A[200][200];    // 100 100
int hr = 0;    // human region
int cr = 0;    // animal region
char cc = 0;   // current color
bool visited[200][200];
queue<pair <int, int>> q;

int N;
void insert(int i, int j, char cc, int t){
   for(int dir=0; dir<4; dir++){
      int nx = i + X[dir];
      int ny = j + Y[dir];
      if(nx<N && nx>=0 && ny<N && ny>=0 && !visited[nx][ny]){
         bool match = (t==0) ? (cc == A[nx][ny] || (cc == 'G' && A[nx][ny] == 'R') || (cc == 'R' && A[nx][ny] == 'G')) : (cc == A[nx][ny]);

         if(match){
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
         }
      }
   }
}
void f(int t){          // 0 : cr   // 1 : hr
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         if(!visited[i][j]){
            (t==0) ? cr++ : hr++;
            int cc = A[i][j];
            while(!q.empty()){
               q.pop();
            }
            q.push(make_pair(i, j));
            visited[i][j] = true;
            while(!q.empty()){
               int nx = q.front().first;
               int ny = q.front().second;
               q.pop();
               insert(nx, ny, cc, t);
            }
         }
      }
   }
}

int main(){
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      scanf("%s", A[i]);
   }
   f(0);
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         visited[i][j] = false;
      }
   }
   f(1);
   printf("%d %d\n", hr, cr);
}
