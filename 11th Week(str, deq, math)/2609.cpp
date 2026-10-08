#include <bits/stdc++.h>
using namespace std;

int N, M;

int gcd(int a, int b){
   if(a%b == 0)   return b;
   else  return gcd(b, a%b);
}
int lcm(int a, int b){
   return a*b/gcd(a, b);
}
int main(){
   scanf("%d %d", &N, &M);
   printf("%d\n", gcd(max(N,M), min(N, M)));
   printf("%d\n", lcm(max(N,M), min(N, M)));
   return 0;
}
