#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> lis[60000];    // 50000
queue<pair <int, char>> q;
char color[60000];
bool visited[60000];
int total = 0;

void BFS(int n){
   int fc = 1;    // fcount
   int jc = 0;
   q.push(make_pair(n, 'F'));
   visited[n] = true;
   while(!q.empty()){
      pair<int, char> v = q.front();
      q.pop();
      for(int i=0; i<lis[v.first].size(); i++){
         if(!visited[lis[v.first][i]]){
            visited[lis[v.first][i]] = true;
            if(v.second == 'F'){
               q.push(make_pair(lis[v.first][i], 'J'));
               color[lis[v.first][i]] = 'J';
               jc++;
            }
            else if(v.second == 'J'){
               q.push(make_pair(lis[v.first][i], 'F'));
               color[lis[v.first][i]] = 'F';
               fc++;
            }
         }
         else{
            if(v.second == color[lis[v.first][i]]){
               printf("-1\n");
               exit(0);
            }
         }
      }
   }
   total += max(fc, jc);
}


int main(){
   scanf("%d %d", &N, &M);
   for(int i=1; i<=M; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      lis[a].push_back(b);
      lis[b].push_back(a);
   }
   for(int i=1; i<=N; i++){
      if(!visited[i]){
         BFS(i);
      }
   }
   printf("%d\n", total);
}
