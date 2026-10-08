#include <bits/stdc++.h>
using namespace std;
bool A[20000000];
vector<int> B;
int N;

int main(){
   scanf("%d", &N);
   for(int i=2; i<10000000; i++){
      if(A[i])  continue;
      B.push_back(i);
      for(long long j=1LL*i*i; j<10000000; j+=i){
         A[j] = true;
      }
   }
   for(int i=2; i*i <= N; i++){
      while(N % i == 0){
         N/=i;
         printf("%d\n", i);
      }
   }
   if(N != 1)  printf("%d\n", N);
   return 0;
}
