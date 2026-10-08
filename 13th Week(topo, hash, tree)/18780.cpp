#include <bits/stdc++.h>
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;

int indegree[200000];
vector<pll> A[200000];
int N, M, C;
int S[200000];
int O[200000];
queue<pll> q;

int main(){
   scanf("%d %d %d", &N, &M, &C);
   for(int i=1; i<=N; i++){
      scanf("%d", &S[i]);
      O[i] = S[i];
   }
   for(int i=0; i<C; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      A[a].push_back({b, c});
      indegree[b]++;
   }
   for(int i=1; i<=N; i++){
      if(indegree[i] == 0) q.push({i, O[i]});
   }
   int days = 0;
   while(!q.empty()){
      pll v = q.front();
      q.pop();
      for(pll i : A[v.ff]){
         O[i.ff] = max(O[i.ff], i.ss + v.ss);
         indegree[i.ff]--;
         if(indegree[i.ff] == 0){
            q.push({i.ff, O[i.ff]});
         }
      }
   }
   for(int i=1; i<=N; i++){
      printf("%d\n", O[i]);
   }
   return 0;
}
