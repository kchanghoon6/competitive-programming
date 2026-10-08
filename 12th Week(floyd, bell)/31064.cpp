#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
int N;
int A[500000];
vector<int> B; // 1쌍 집합

int main(){
   scanf("%d", &N);
   int cnt = 0;
   int mini = 1e9;
   for(int i=0; i<N; i++){
      scanf("%1d", &A[i]);
      if(A[i] == 1){
         cnt++;
      }
      else if(cnt != 0){
         if((B.empty() && A[0]==1)){
            mini = min(mini, cnt-1);
         }
         else{
            mini = min(mini, (cnt-1)/2);
         }
         B.push_back(cnt);
         cnt = 0;
      }
   }
   if(cnt != 0){
      mini = min(mini, cnt-1);
      B.push_back(cnt);
   }
   int sum = 0;
   for(auto i : B){
      sum += (i+2*mini)/(2*mini+1);
   }
   printf("%d\n", sum);
   return 0;
}
