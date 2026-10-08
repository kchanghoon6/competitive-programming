#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t;
char A[50][50];
char B[4][50][50];
ll covered[50][50];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> t;
   while(t--){
      ll n, k;
      cin >> n;
      for(ll i=0; i<n; i++){
         cin >> A[i];
      }
      cin >> k;
      for(ll i=0; i<k; i++){
         cin >> B[0][i];
      }
      for(ll r=1; r<4; r++){
         for(ll i=0; i<k; i++){
            for(ll j=0; j<k; j++){
               B[r][i][j] = B[r-1][j][k-1-i];
            }
         }
      }
      memset(covered, 0, sizeof(covered));
      for(ll i=0; i<=n-k; i++){
         for(ll j=0; j<=n-k; j++){
            for(ll r=0; r<4; r++){
               ll flag = 1;
               for(ll di=0; di<k && flag; di++){
                  for(ll dj=0; dj<k && flag; dj++){
                     if(B[r][di][dj] == '*' && A[i+di][j+dj] == '.'){
                        flag = 0;
                     }
                  }
               }
               if(flag){
                  for(ll di=0; di<k; di++){
                     for(ll dj=0; dj<k; dj++){
                        if(B[r][di][dj] == '*'){
                           covered[i+di][j+dj] = 1;
                        }
                     }
                  }
               }
            }
         }
      }
      ll flag = 1;
      for(ll i=0; i<n && flag; i++){
         for(ll j=0; j<n && flag; j++){
            if(A[i][j] == '*' && !covered[i][j]){
               flag = 0;
            }
         }
      }

      cout << (flag ? "YES" : "NO") << "\n";
   }

   return 0;
}
