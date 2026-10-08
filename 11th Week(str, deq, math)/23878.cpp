#include <bits/stdc++.h>
using namespace std;

int main(){
   int N;
   cin >> N;
   string A;
   cin >> A;

   int s = 0, e = 0;
   int lonely = 0;

   while(s < N-2){
      int cnt_h = 0;
      for(int e = s; e < N; e++){
         if(A[e] == 'H') cnt_h++;
         if(cnt_h > 1) break;
         if(cnt_h == 1 && e - s + 1 >= 3)
            lonely++;
      }

      int cnt_g = 0;
      for(int e = s; e < N; e++){
         if(A[e] == 'G') cnt_g++;
         if(cnt_g > 1) break;
         if(cnt_g == 1 && e - s + 1 >= 3)
            lonely++;
      }
   }
   printf("%d\n", lonely);
   return 0;
}
