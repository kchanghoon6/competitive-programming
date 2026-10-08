#include <bits/stdc++.h>
using namespace std;
int a1, a2;
int b1, b2;
int A[1000];
int B[1000];
int main(){
   int N, K;
   scanf("%d %d", &N, &K);
   scanf("%d %d", &a1, &a2);
   scanf("%d %d", &b1, &b2);
   for(int i=1; i<=N; i++){
      A[i] = i;
      B[i] = i;
   }
   bool flag = true;
   int cnt = 0;
   do{
      if(cnt >= 1)   flag = false;
      for(int i=1; i<=N; i++){
         if(A[i] != B[i]){
            flag = true;
         }
      }
      if(!flag)   break;
      int j = 0;
      for(int i=a1; i<=a2-j; i++){
         swap(B[i], B[a2-j]);
         j++;
      }
      j = 0;
      for(int i=b1; i<=b2-j; i++){
         swap(B[i], B[b2-j]);
         j++;
      }
      cnt++;
   } while(flag);
   for(int k=0; k<K%cnt; k++){
      int j = 0;
      for(int i=a1; i<=a2-j; i++){
         swap(A[i], A[a2-j]);
         j++;
      }
      j = 0;
      for(int i=b1; i<=b2-j; i++){
         swap(A[i], A[b2-j]);
         j++;
      }
   }
   for(int i=1; i<=N; i++){
      printf("%d\n", A[i]);
   }

   return 0;
}
