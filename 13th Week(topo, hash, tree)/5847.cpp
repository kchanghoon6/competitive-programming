#include <bits/stdc++.h>
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;

vector<int> A[60000];
int B[60000];
int C[60000];
int indegree[60000];
queue<int> q;

int main(){
   int N, M;
   scanf("%d %d", &N, &M);
   for(int i=1; i<=N; i++){
      scanf("%d", &B[i]);
      C[i] = B[i];
   }
   for(int i=1; i<=M; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      A[a].push_back(b);
      indegree[b]++;
   }
   for(int i=1; i<=N; i++){
      if(indegree[i]==0){
         q.push(i);
      }
   }
   while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto i : A[v]){
         indegree[i]--;
         C[i] = max(C[i], B[i]+C[v]);
         if(indegree[i] == 0){
            q.push(i);
         }
      }
   }
   int maxi = 0;
   for(int i=1; i<=N; i++){
      maxi = max(maxi, C[i]);
   }
   printf("%d\n", maxi);
   return 0;
}
