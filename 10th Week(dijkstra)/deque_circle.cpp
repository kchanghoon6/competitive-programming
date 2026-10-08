#include <bits/stdc++.h>

int A[10000];
int s = 0;
int e = 0;
int N = 10000;
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
   return 0;
}
