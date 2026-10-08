#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;
char A[600][600];
set<string> B;
int main(){
   scanf("%lld %lld", &N, &M);
   for(int i=0; i<2*N; i++){
      scanf("%s", A[i]);
   }
   ll cnt = 0;
   for(ll i=0; i<M; i++){
      for(ll j=i+1; j<M; j++){
         for(ll k=j+1; k<M; k++){
            for(ll l=0; l<N; l++){
               string str;
               str += A[l][i];
               str += A[l][j];
               str += A[l][k];
               B.insert(str);
            }
            for(ll l=N; l<2*N; l++){
               string str;
               str += A[l][i];
               str += A[l][j];
               str += A[l][k];
               if(B.count({A[l][i], A[l][j], A[l][k]})){
                  break;
               }
               if(l==2*N-1){
                  cnt++;
               }
            }
            B.clear();
         }
      }
   }
   printf("%lld\n", cnt);

   return 0;
}
