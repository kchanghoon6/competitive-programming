#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
pii A[200000];

int main(){
   int N;
   scanf("%d", &N);

   for(int i=0; i<N; i++){
      int a, b;
      scanf("%d %d", &a, &b);
      A[i].ff = b;
      A[i].ss = a;
   }
   sort(A, A+N);
   int s = 0;
   int e = N-1;
   int maxi = 0;
   while(s <= e){
      int sum = A[s].ff + A[e].ff;
      maxi = max(maxi, sum);

      if(A[e].ss == 0)  e--;
      A[e].ss--;
      if(A[s].ss == 0)  s++;
      A[s].ss--;
   }
   printf("%d\n", maxi);
   return 0;
}
