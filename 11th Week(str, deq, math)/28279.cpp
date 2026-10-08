#include <bits/stdc++.h>
using namespace std;

int main(){
   deque<int> d;
   int N;
   scanf("%d", &N);

   for(int i = 0; i < N; i++){
      int a;
      scanf("%d", &a);

      if(a == 1){
         int b;
         scanf("%d", &b);
         d.push_front(b);
      }
      else if(a == 2){
         int b;
         scanf("%d", &b);
         d.push_back(b);
      }
      else if(a == 3){
         if(!d.empty()){
            printf("%d\n", d.front());
            d.pop_front();
         }
         else{
            printf("-1\n");
         }
      }
      else if(a == 4){
         if(!d.empty()){
            printf("%d\n", d.back());
            d.pop_back();
         }
         else{
            printf("-1\n");
         }
      }
      else if(a == 5){
         printf("%d\n", (int)d.size());
      }
      else if(a == 6){
         printf("%d\n", d.empty() ? 1 : 0);
      }
      else if(a == 7){
         if(!d.empty()){
            printf("%d\n", d.front());
         }
         else{
            printf("-1\n");
         }
      }
      else if(a == 8){
         if(!d.empty()){
            printf("%d\n", d.back());
         }
         else{
            printf("-1\n");
         }
      }
   }
   return 0;
}
