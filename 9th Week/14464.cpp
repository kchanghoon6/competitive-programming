#include <bits/stdc++.h>
using namespace std;
int c, n;
int C[30000];  // 20000 chicken time
pair<int, int> A[30000];  // 20000 cow time start, end
bool oc[30000];
priority_queue<pair<int, int>> pq;

struct PairCmp {
   bool operator()(pair<int,int> a, pair<int,int> b) const {
      if(a.second != b.second) return a.second < b.second;
      return a.first  < b.first;
   }
};

int main(){
   scanf("%d %d", &c, &n);
   for(int i=0; i<c; i++){
      scanf("%d", &C[i]);
   }
   for(int i=0; i<n; i++){
      scanf("%d %d", &A[i].first, &A[i].second);
   }

   sort(C, C+c);
   sort(A, A+n);
   int cnt = 0;
   for(int i=0; i<c; i++){
      for(int j=0; C[i]>=A[j].first; j++){
         if(!oc[j]){
            pq.push(make_pair(A[j].first, -A[j].second));
            oc[j] = true;
         }
      }
      for(int j=0; pq.top().second > -C[i]; j++){
         pq.pop();
      }
      if(!pq.empty()){
         cnt++;
      }
      while(!pq.empty()){
         pq.pop();
      }
   }
   printf("%d\n", cnt);
}
