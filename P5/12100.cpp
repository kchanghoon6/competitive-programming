#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll B[30][30];
ll maxi = 0;

void f(ll dir, ll A[30][30], ll k, ll num){
   if(num == 5){
      maxi = max(k, maxi);
      return;
   }
   ll temp[30][30];
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         temp[i][j] = A[i][j];
      }
   }
   // 위
   if(dir == 1){
      for(ll j=1; j<=N; j++){
         ll idx = 1;
         ll prev = 0;
         for(ll i=1; i<=N; i++){
            if(temp[i][j] != 0){
               if(prev == temp[i][j]){
                  temp[idx-1][j] = prev * 2;
                  k = max(temp[idx-1][j], k);
                  temp[i][j] = 0;
                  prev = 0;
               } else{
                  prev = temp[i][j];
                  temp[i][j] = 0;
                  temp[idx][j] = prev;
                  idx++;
               }
            }
         }
      }
   }
   // 아래
   else if(dir == 2){
      for(ll j=1; j<=N; j++){
         ll idx = N;
         ll prev = 0;
         for(ll i=N; i>=1; i--){
            if(temp[i][j] != 0){
               if(prev == temp[i][j]){
                  temp[idx+1][j] = prev * 2;
                  k = max(temp[idx+1][j], k);
                  temp[i][j] = 0;
                  prev = 0;
               } else{
                  prev = temp[i][j];
                  temp[i][j] = 0;
                  temp[idx][j] = prev;
                  idx--;
               }
            }
         }
      }
   }
   // 오른쪽
   else if(dir == 3){
      for(ll i=1; i<=N; i++){
         ll idx = N;
         ll prev = 0;
         for(ll j=N; j>=1; j--){
            if(temp[i][j] != 0){
               if(prev == temp[i][j]){
                  temp[i][idx+1] = prev * 2;
                  k = max(temp[i][idx+1], k);
                  temp[i][j] = 0;
                  prev = 0;
               } else{
                  prev = temp[i][j];
                  temp[i][j] = 0;
                  temp[i][idx] = prev;
                  idx--;
               }
            }
         }
      }
   }
   // 왼쪽
   else{
      for(ll i=1; i<=N; i++){
         ll idx = 1;
         ll prev = 0;
         for(ll j=1; j<=N; j++){
            if(temp[i][j] != 0){
               if(prev == temp[i][j]){
                  temp[i][idx-1] = prev * 2;
                  k = max(temp[i][idx-1], k);
                  temp[i][j] = 0;
                  prev = 0;
               } else{
                  prev = temp[i][j];
                  temp[i][j] = 0;
                  temp[i][idx] = prev;
                  idx++;
               }
            }
         }
      }
   }

   num++;
   f(1, temp, k, num);
   f(2, temp, k, num);
   f(3, temp, k, num);
   f(4, temp, k, num);
   return;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=N; j++){
         cin >> B[i][j];
         maxi = max(maxi, B[i][j]);
      }
   }
   f(1, B, maxi, 0);
   f(2, B, maxi, 0);
   f(3, B, maxi, 0);
   f(4, B, maxi, 0);
   cout << maxi << "\n";



   return 0;
}
