#include <bits/stdc++.h>
using namespace std;

vector<int> A[50000];
int indegree[50000];
queue<int> q;
int main(){
   int N, M;
   scanf("%d %d", &N, &M);
   for(int i=0; i<M; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      A[a].push_back(b);
      indegree[b]++;
   }
   for(int i=1; i<=N; i++){
      if(indegree[i] == 0){
         q.push(i);
      }
   }
   while(!q.empty()){
      int v = q.front();
      q.pop();
      printf("%d ", v);
      for(auto i : A[v]){
         indegree[i]--;
         if(indegree[i] == 0) q.push(i);
      }
   }
   printf("\n");
   return 0;
}
