#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[1000][1000];
ll a[1000][1000];
ll N;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N;
   for(ll i=1; i<N; i++){
      string s;
      cin >> s;
      ll slen = s.size();
      for(ll j=1; j<=slen; j++){
         cnt[i][i+j] = s[j-1];
      }
   }
   for(ll j=1; j<=N; j++){
      for(ll i=j-1; i>=1; i--){
         ll s = 0;
         for(ll k=i+1; k<j; k++){
            s += (cnt[k][j]*a[i][k])%2;
         }
         a[i][j] = ((cnt[i][j]-s)%2+2)%2;
      }
   }
   ll res = 0;
   for(ll i=1; i<N; i++){
      for(ll j=i+1; j<=N; j++){
         res += a[i][j]%2;
      }
   }
   cout << res << "\n";



   return 0;
}
