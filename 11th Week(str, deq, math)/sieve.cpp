#include <bits/stdc++.h>
using namespace std;
bool A[10000];
vector<int> B;
int main(){
   int N, M;
   scanf("%d", &N);
   scanf("%d", &M);
   for(int i=2; i<N; i++){
      if(A[i] == true)  continue;
      B.push_back(i);
      for(int j=i*i; j<N; j+=i){
         A[j] = true;
      }
   }
   // for(int i=0; i<B.size(); i++){
   //    int cnt = 0;
   //    while(M % B[i] == 0){
   //       cnt++;
   //       M /= B[i];
   //    }
   //    if(cnt >= 1)   printf("%d^%d ", B[i], cnt);
   // }
   for(int i=2; i*i <= M; i++){
      while(M % i == 0){
         M/=i;
         printf("%d\n", i);
      }
   }
   if(M != 1)  printf("%d\n", M);

   return 0;
}
