#include <bits/stdc++.h>
using namespace std;

int A[20000];
int main(){
   int N;
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      int a;
      scanf("%d", &a);
      A[a]++;
   }
   for(int i=1; i<=10000; i++){
      for(int j=0; j<A[i]; j++){
         printf("%d\n", i);
      }
   }
}
