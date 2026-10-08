#include <bits/stdc++.h>
using namespace std;
struct PairInt {
   int first;
   int second;
   bool operator<(const PairInt& other) const{  return first < other.first;
   }
};
// + - * /      1, 2, 3, 4
int main(){
   char array[110];
   scanf("%s", array);
   priority_queue<PairInt> pq;
   queue<char> q;
   int extra = 0;

   for(int i=0; array[i]!='\0'; i++){
      if(array[i] == '('){
         extra += 2;
      }
      else if(array[i] == ')'){
         extra -= 2;
      }
      else if(array[i] == '+'){
         pq.push({1+extra, 1});
      }
      else if(array[i] == '-'){
         pq.push({1+extra, 2});
      }
      else if(array[i] == '*'){
         pq.push({2+extra, 3});
      }
      else if(array[i] == '/'){
         pq.push({2+extra, 4});
      }
      else{
         q.push(array[i]);
      }
   }
   while(!pq.empty()){
      if(pq.top().first%2 == 1){
         if(pq.top().second == 1){
            printf("+");
         }
         else{
            printf("-");
         }
      }
      else if(pq.top().first%2 == 0){
         if(pq.top().second == 3){
            printf("*");
         }
         else{
            printf("/");
         }
      }
      pq.pop();
   }
   printf("\n");
}
