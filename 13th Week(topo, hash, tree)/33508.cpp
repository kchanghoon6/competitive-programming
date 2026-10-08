#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

ll A[1000030];
ll tot[1000030];
ll cnt[1000030];
bool checked[1000030];
int main(){
   ll N;
   cin >> N;
   for(ll i=0; i<N; i++){
      cin >> A[i];
      tot[A[i]]++;
   }
   ll doubles = 0;
   ll result = 0;
   for(ll i=N-1; i>=0; i--){
      ll num = A[i];
      if(cnt[num] == 1){
         doubles++;
         checked[num] = true;
      }
      cnt[num]++;
      if(cnt[num] == tot[num]){
         result += (doubles-checked[num]);
      }
   }
   printf("%lld\n", result);
   return 0;
}
