#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, M;
char A[1100][1100];
set<vector<pll>> B;
ll X[] = {1, -1, 0, 0};
ll Y[] = {0, 0, 1, -1};
int main(){
   scanf("%lld %lld", &N, &M);
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=M; j++){
         scanf(" %c", &A[i][j]);
      }
   }
   ll result = 0;
   for(ll i=1; i<=N; i++){
      for(ll j=1; j<=M; j++){
         vector<pll> v;
         if(A[i][j] == 'G'){
            ll cnt = 0;
            for(ll k=0; k<4; k++){
               ll nx = i+X[k];
               ll ny = j+Y[k];
               if(nx>=1 && nx <=N && ny>=1 && ny <=M && A[nx][ny] == 'C'){
                  cnt++;
                  v.push_back({nx, ny});
               }
            }
            if(cnt > 2){
               result++;
            }
            else if(cnt == 2){
               sort(v.begin(), v.end());
               B.insert(v);
            }
         }
      }
   }
   printf("%lld\n", result+B.size());
   return 0;
}
