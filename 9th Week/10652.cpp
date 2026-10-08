#include <bits/stdc++.h>
using namespace std;
int b_unit, e_unit, p_unit, N, M;
int A[5][50000]; // B, E, N
vector<int> lis[50000]; // 40000
queue<int> q;
bool visited[50000];

void BFS(int w){
   int temp;
   for(int i=1; i<=N; i++){
      visited[i] = false;
   }
   if(w == 1 || w == 2) temp = w;
   else if(w == 3) temp = N;
   A[w][temp] = 0;
   visited[temp] = true;
   q.push(temp);
   while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int i=0; i<lis[v].size(); i++){
         if(!visited[lis[v][i]]){
            q.push(lis[v][i]);
            visited[lis[v][i]] = true;
            A[w][lis[v][i]] = A[w][v] + 1;
         }
      }
   }
}

int main(){
   scanf("%d %d %d %d %d", &b_unit, &e_unit, &p_unit, &N, &M);
   for(int i=0; i<M; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      lis[a].push_back(b);
      lis[b].push_back(a);
   }
   for(int w=1; w<=3; w++){
      BFS(w);
   }
   int mini = A[1][1]*b_unit + A[2][1]*e_unit + A[3][1]*p_unit;
   for(int i=1; i<=N; i++){
      int total = A[1][i]*b_unit + A[2][i]*e_unit + A[3][i]*p_unit;
      mini = min(mini, total);
   }
   printf("%d\n", mini);
}
