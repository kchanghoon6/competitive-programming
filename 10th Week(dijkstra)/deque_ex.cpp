#include <bits/stdc++.h>
using namespace std;

int A[10000];
int s = 5000;
int e = 5000;

void push_front(int k){
   A[s--] = k;
}
void pop_front(){
   s++;
}
void push_back(int k){
   A[++e] = k;
}
void pop_back(){
   e--;
}
int size(){
   return e-s;
}

int main(){


   return 0;
}
