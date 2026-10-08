#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

char A[500][500];
set<string> B[5][200];
ll N;
ll X[] = {0, 1, 0, -1};
ll Y[] = {1, 0, -1, 0};


void DFS1(ll x, ll y, string str){
   str += A[x][y];
   if(x+y == N-1){
      B[0][y].insert(str);
      return;
   }
   for(ll i=0; i<2; i++){
      ll nx = x+X[i];
      ll ny = y+Y[i];
      if(nx < N && ny < N){
         DFS1(nx, ny, str);
      }
   }
}
void DFS2(ll x, ll y, string str){
   str += A[x][y];
   if(x+y == N-1){
      B[1][y].insert(str);
      return;
   }
   for(ll i=2; i<4; i++){
      ll nx = x+X[i];
      ll ny = y+Y[i];
      if(nx >= 0 && ny >= 0){
         DFS2(nx, ny, str);
      }
   }
}

int main(){
   scanf("%lld", &N);
   for(ll i=0; i<N; i++){
      scanf("%s", A[i]);
   }
   DFS1(0, 0, "");
   DFS2(N-1, N-1, "");
   ll cnt = 0;
   set<string> C;
   for(ll i=0; i<N; i++){
      map<string, ll> P;
      for(auto j : B[0][i]){
         P[j]++;
      }
      for(auto j : B[1][i]){
         if(P.count(j) && C.find(j) == C.end()){
            C.insert(j);
            cnt++;
         }
      }
   }
   printf("%lld\n", cnt);
}
