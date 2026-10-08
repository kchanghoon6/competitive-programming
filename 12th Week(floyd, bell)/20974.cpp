#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;

int A[10000];
vector<int> odd;
vector<int> even;
int main(){
   int N;
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      scanf("%d", &A[i]);
   }
   for(int i=0; i<N; i++){
      if(A[i]%2 == 1)   odd.push_back(A[i]);
      else  even.push_back(A[i]);
   }
   int odd_num = odd.size();
   int even_num = even.size();

   if(even_num > odd_num){
      printf("%d\n", 2*odd_num+1);
   }
   else if(even_num == odd_num){
      printf("%d\n", 2*odd_num);
   }
   else{
      int result = 2*even_num;
      int k = (odd_num - even_num);
      if(k%3 == 1){
         result += (k/3)*2-1;
      }
      else if(k%3 == 2){
         result += (k/3)*2+1;
      }
      else{
         result += (k/3)*2;
      }
      printf("%d\n", result);
   }
   return 0;
}
