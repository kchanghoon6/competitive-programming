#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A[200000];
int P[200000];

void make_tree(int node, int par){
   P[node] = par;
   for(auto i : A[node]){
      if(i == par)   continue;
      make_tree(i, node);
   }
}


int main(){
   scanf("%d", &N);
   for(int i=0; i<N-1; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      A[a].push_back(b);
      A[b].push_back(a);
   }
   make_tree(1, -1);
   for(int i=2; i<=N; i++){
      printf("%d\n", P[i]);
   }

   return 0;
}
