#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<int> lis[1010];
bool checked[1010];
bool checked2[1010];

void DFS(int k){
  for(int i=0; i<lis[k].size(); i++){
    if(!checked[lis[k][i]]){
      printf("%d ", lis[k][i]);
      checked[lis[k][i]] = true;
      DFS(lis[k][i]);
    }
  }
  return;
}
int main()
{
  scanf("%d%d%d", &N, &M, &V);
  for(int i = 0; i < M; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    lis[a].push_back(b);
    lis[b].push_back(a);
  }
  for(int i=1; i<=N; i++){
    for(int j=0; j<lis[i].size(); j++){
      for(int k=0; k<lis[i].size()-1; k++){
        if(lis[i][k] > lis[i][k+1]){
          int temp = lis[i][k];
          lis[i][k] = lis[i][k+1];
          lis[i][k+1] = temp;
        }
      }
    }
  }
  printf("%d ", V);
  checked[V] = true;
  DFS(V);
  printf("\n");
  // queue
  queue<int> q;
  printf("%d ", V);
  checked2[V] = true;
  q.push(V);
  int count = 0;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int i=0; i<lis[v].size(); i++){
      if(!checked2[lis[v][i]]){
        printf("%d", lis[v][i]);
        q.push(lis[v][i]);
        checked2[lis[v][i]] = true;
        count++;
        if(count != N-1){
          printf(" ");
        }
      }
    }
  }
  printf("\n");
  return 0;
}
