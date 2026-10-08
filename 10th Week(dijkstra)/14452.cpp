#include <bits/stdc++.h>
using namespace std;
int N;
int T_MAX;
int A[15000];   // 10000


bool f(int k){
   priority_queue<int, vector<int>, greater<int>> pq;
   int i = 0;
   for(i = 0; i<k; i++){
      pq.push(A[i]);
   }
   while(i<N){
      int earliest = pq.top();
      pq.pop();
      if(earliest + A[i] > T_MAX) return false;
      pq.push(earliest+A[i]);
      i++;
   }
   return true;
}


int main(){
   scanf("%d %d", &N, &T_MAX);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   int s = 1;
   int e = N;
   int ans = N;
   while(s <= e){
      int mid = (s+e)/2;
      if(f(mid)){
         ans = mid;
         e = mid - 1;
      }
      else{
         s = mid + 1;
      }
   }
   printf("%d\n", ans);
   return 0;
}
