#include <bits/stdc++.h>
using namespace std;

int A, B, D;
vector<int> P;
bool pc[5000000];
int main(){
   scanf("%d %d %d", &A, &B, &D);
   for(int i=2; i<=4000000; i++){
      if(pc[i])   continue;
      P.push_back(i);
      for(long long j=1LL*i*i; j<=4000000; j+=i){
         pc[j] = true;
      }
   }
   int len_P = P.size();
   int sum = 0;
   for(int i=A; i<=B; i++){
      int s = 0;
      int e = len_P-1;
      bool is_prime = false;
      while(s <= e){
         int mid = (s+e)/2;
         if(P[mid] > i){
            e = mid-1;
         }
         else if(P[mid] < i){
            s = mid+1;
         }
         else{
            is_prime = true;
            break;
         }
      }
      if(is_prime){
         string s = to_string(i);
         if(s.find(to_string(D)) != string::npos){
            sum++;
         }
      }
   }
   printf("%d\n", sum);

   return 0;
}
