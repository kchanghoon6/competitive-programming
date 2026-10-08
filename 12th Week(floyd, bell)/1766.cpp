#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> A[50000];
int indegree[50000];
int N, M;
int main(){
   scanf("%d %d", &N, &M);
   for(int i=0; i<M; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      A[a].push_back(b);
      indegree[b]++;
   }
   for(int i=1; i<=N; i++){
      if(indegree[i] == 0){
         pq.push(i);
      }
   }
   while(!pq.empty()){
      int v = pq.top();
      pq.pop();
      printf("%d ", v);
      for(auto i : A[v]){
         indegree[i]--;
         if(indegree[i] == 0) pq.push(i);
      }
   }
   printf("\n");
   return 0;
}
