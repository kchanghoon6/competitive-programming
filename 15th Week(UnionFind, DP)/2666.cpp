#include <bits/stdc++.h>
using namespace std;

int N, K, a, b;
int A[500];
int mini = 1e9;

void f(int i, int x, int y, int cost){
   if(i==K){
      mini = min(mini, cost);
      return;
   }
   f(i+1, A[i], y, cost+abs(A[i]-x));
   f(i+1, x, A[i], cost+abs(A[i]-y));
}

int main(){
   scanf("%d", &N);
   scanf("%d %d", &a, &b);
   scanf("%d", &K);
   for(int i=0; i<K; i++){
      scanf("%d", &A[i]);
   }
   f(0, a, b, 0);
   printf("%d\n", mini);

   return 0;
}
