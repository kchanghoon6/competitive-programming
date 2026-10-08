#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;


int T;
vector<int> A[600];
vector<int> B;
int main(){
   scanf("%d", &T);
   while(T--){
      int N, M;
      scanf("%d", &N);
      for(int i=1; i<=N; i++){
         A[i].clear();
      }
      B.clear();
      bool visited[600] = {false};
      int indegree[600] = {0};
      for(int i=1; i<=N; i++){
         int a;
         scanf("%d", &a);
         for(int j=1; j<=N; j++){
            if(!visited[j] && a!=j){
               A[a].push_back(j);
               indegree[j]++;
            }
         }
         visited[a] = true;
      }
      scanf("%d", &M);
      for(int i=1; i<=M; i++){
         int a, b;
         scanf("%d %d", &a, &b);
         bool found = false;
         for(auto j : A[a]){
            if(j == b){
               A[b].push_back(a);
               indegree[a]++;
               A[a].erase(remove(A[a].begin(), A[a].end(), b), A[a].end());
               indegree[b]--;
               found = true;
               break;
            }
         }
         if(!found){
            for(auto j : A[b]){
               if(j == a){
                  A[a].push_back(b);
                  indegree[b]++;
                  A[b].erase(remove(A[b].begin(), A[b].end(), a), A[b].end());
                  indegree[a]--;
                  break;
               }
            }
         }
      }
      queue<int> q;
      for(int i=1; i<=N; i++){
         if(indegree[i] == 0){
            q.push(i);
         }
      }
      if(q.empty()){
         printf("IMPOSSIBLE\n");
         continue;
      }
      bool flag = false;
      while(!q.empty()){
         if(q.size() > 1){
            flag = true;
         }
         int v = q.front();
         q.pop();
         B.push_back(v);
         for(auto i : A[v]){
            if(--indegree[i] == 0){
               q.push(i);
            }
         }
      }
      if(B.size() < N){
         printf("IMPOSSIBLE\n");
      }
      else if(flag)  printf("?\n");
      else{
         for(auto i : B){
            printf("%d ", i);
         }
         printf("\n");
      }
   }
   return 0;
}
