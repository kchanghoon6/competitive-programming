#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[40000];
vector<int> L;
bool ch[40000];
int gcd(int a, int b){
   if(a%b == 0)   return b;
   else  return gcd(b, a%b);
}
int lcm(int a, int b){
   return a*b/gcd(a, b);
}

int main(){
   int N;
   scanf("%d", &N);

   for(int i=1; i<=N; i++){
      scanf("%d", &A[i]);
   }
   for(int i=1; i<=N; i++){
      if(!ch[i]){
         int cnt = 1;
         for(int j=A[i]; !ch[j] && i != j; j=A[j]){
            cnt++;
            ch[j] = true;
         }
         L.push_back(cnt);
      }
   }
   int len_L = L.size();
   ll result = L[0];
   for(int i=1; i<len_L; i++){
      result = lcm((ll)L[i], result);
   }
   printf("%lld\n", result);
   return 0;
}
