#include <bits/stdc++.h>
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;

int dollar[700];
vector<pair<pll, int>> A;
int D, P, C, F, S;

bool bellman_ford(int st){
   for(int i=1; i<=C; i++){
      dollar[i] = 1e9;
   }
   dollar[st] = -D;
   for(int i=0; i<=P+F-1; i++){
      for(auto j : A){
         if(dollar[j.ff.ss] > dollar[j.ff.ff] + j.ss){
            if(i==P+F-1)   return 1;
            dollar[j.ff.ss] = dollar[j.ff.ff] + j.ss;
         }
      }
   }
   return 0;
}

int main(){
   scanf("%d %d %d %d %d", &D, &P, &C, &F, &S);
   for(int i=0; i<P; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      A.push_back({{a, b}, -D});
   }
   for(int i=0; i<F; i++){
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      A.push_back({{a, b}, -D+c});
   }
   if(bellman_ford(S)){
      printf("-1\n");
   }
   else{
      int mini = 1e9;
      for(int i=1; i<=C; i++){
         mini = min(mini, dollar[i]);
      }
      printf("%d\n", -mini);
   }
   return 0;
}
