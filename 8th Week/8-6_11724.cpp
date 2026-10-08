#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
vector<int> lis[1010];
bool checked[1010];

void DFS(int k){
  for(int i=0; i<lis[k].size(); i++){
    if(!checked[lis[k][i]]){
      checked[lis[k][i]] = true;
      DFS(lis[k][i]);
    }
  }
  return;
}

int main(){
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    lis[a].push_back(b);
    lis[b].push_back(a);
  }
  int count = 0;
  for(int i=1; i<=N; i++){
    if(!checked[i]){
      count++;
      DFS(i);
    }
  }
  printf("%d\n", count);
}
