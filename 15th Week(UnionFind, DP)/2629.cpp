// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;


// ll N, K;
// ll A[50]; // 추 무게
// ll dp[50000]; // 무게
// ll visited[50][50000];

// void f(ll i, ll diff){
//    if(visited[i][abs(diff)])  return;
//    if(i > N){
//       dp[abs(diff)] = 1;
//       visited[i][abs(diff)] = 1;
//       return;
//    }
//    f(i+1, diff);
//    f(i+1, diff-A[i]);
//    f(i+1, diff+A[i]);
// }

// int main(){
//    scanf("%lld", &N);
//    for(ll i=1; i<=N; i++){
//       scanf("%lld", &A[i]);
//    }
//    scanf("%lld", &K);
//    f(1, 0);
//    for(ll i=1; i<=K; i++){
//       ll b;
//       scanf("%lld", &b);
//       if(dp[b])   printf("Y ");
//       else  printf("N ");
//    }
//    printf("\n");
//    return 0;
// }

#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, S; // 추 개수, 구슬 개수
ll A[50];
ll B[50];
ll dp[50][50000];
int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &A[i]);
   }
   dp[0][0] = 1;
   for(ll i=1; i<=N; i++){
      for(ll j=0; j<=45000; j++){
         if(dp[i-1][j]){
            dp[i][abs(j-A[i])] = 1;
            dp[i][j] = 1;
            dp[i][j+A[i]] = 1;
         }
      }
   }
   scanf("%lld", &S);
   for(ll i=1; i<=S; i++){
      ll b;
      scanf("%lld", &b);
      if(dp[N][b])   printf("Y ");
      else  printf("N ");
   }
   printf("\n");

   return 0;
}
