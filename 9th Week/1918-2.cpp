#include <bits/stdc++.h>
using namespace std;

int main(){
   char array[110];
   stack<char> q;
   scanf("%s", array);

   for(int i=0; array[i] != '\0'; i++){
      if(array[i] == '+' || array[i] == '-'){
         while(!q.empty() && q.top() != '('){
            printf("%c", q.top());
            q.pop();
         }
         q.push(array[i]);
      }
      else if(array[i] == '*' || array[i] == '/'){
         while(!q.empty() && (q.top() == '*' || q.top() == '/')){
            printf("%c", q.top());
            q.pop();
         }
         q.push(array[i]);
      }
      else if(array[i] == '('){
         q.push(array[i]);
      }
      else if(array[i] == ')'){
         while(!q.empty() && q.top() != '('){
            printf("%c", q.top());
            q.pop();
         }
         if(!q.empty()) q.pop();
      }
      else{
         printf("%c", array[i]);
      }
   }
   while(!q.empty()){
      printf("%c", q.top());
      q.pop();
   }
   printf("\n");
}
