#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll A[1100][1100];
vector<ll> B[4000];    // 빈도-숫자
ll cnt[4000];     // 숫자-빈도
ll G1[1100][1100];
ll G2[1100][1100];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> N;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         cin >> A[i][j];
         cnt[A[i][j]]++;
      }
   }
   for(ll i=2; i<=N*2; i++){
      B[cnt[i]].push_back(i);
   }
   ll flag = 0;
   ll r, c;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         if(A[i][j] == B[1][0]){
            A[0][j] = 1, A[i][0] = 1;
            r = i, c= j;
            flag = 1;
            break;
         }
      }
      if(flag) break;
   }
   for(ll j=1; j<=N; j++){
      A[0][j] = cnt[A[r][j]];
   }
   for(ll i=1; i<=N; i++){
      A[i][0] = cnt[A[i][c]];
   }
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         G1[i][j] = A[i][0] + A[0][j];
         G2[i][j] = 2*N+2-G1[i][j];
      }
   }
   flag = 0;
   ll flag2 = 0;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         if(G1[i][j] != G2[i][j]){
            flag = (G1[i][j] < G2[i][j]);
            flag2 = 1;
            break;
         }
      }
      if(flag2)   break;
   }
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         if(flag){
            cout << G1[i][j] << " ";
         }
         else{
            cout << G2[i][j] << " ";
         }
      }
      cout << "\n";
   }

   return 0;
}
