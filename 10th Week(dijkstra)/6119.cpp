#include <bits/stdc++.h>
using namespace std;

int A[200000];
int s = 0;
int e = 0;
int N = 200000;
void push_front(int k){
   A[s] = k;
   s = (s - 1 + N) % N;
}
void pop_front(){
   s = (s + 1) % N;
}
void push_back(int k){
   e = (e + 1) % N;
   A[e] = k;
}
void pop_back(){
   e = (e - 1 + N) % N;
}
int size(){
   return s <= e ? e-s : N+e-s;
}

int S;
int main(){
   scanf("%d", &S);
   int cow = 1;
   for(int i=0; i<S; i++){
      char a, b;
      int c;
      scanf(" %c %c", &a, &b);
      if(a == 'A'){
         if(b == 'L'){
            push_front(cow++);
         }
         else{
            push_back(cow++);
         }
      }
      else{
         scanf("%d", &c);
         if(b == 'L'){
            s = (s + c) % N;
         }
         else{
            e = (e - c + N) % N;
         }
      }
   }
   for(int i=0; i<size(); i++){
      printf("%d\n", A[(s+1+i)%N]);
   }
   return 0;
}
