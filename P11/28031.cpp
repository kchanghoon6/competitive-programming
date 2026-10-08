#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n, q;
ll A[200000];
vector<ll> B(200000);
ll sum[200000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);


   cin >> n;
   ll res = 0;
   for(ll i=1; i<=n; i++){
      cin >> A[i];
      B[i] = A[i];
   }
   sort(B.begin()+1, B.begin()+n+1);
   cin >> q;
   sum[1] = B[1];
   res = B[1];
   for(ll i=2; i<=n; i++){
      sum[i] = sum[i-1]+B[i];
      res += i*B[i];
   }
   ll res2 = res;
   while(q--){
      res = res2;
      ll a, b;
      cin >> a >> b;
      ll od = A[a], nw = b;
      if(nw < od){
         ll oidx = lower_bound(B.begin()+1, B.begin()+n+1, od) - B.begin();
         ll nidx = lower_bound(B.begin()+1, B.begin()+n+1, nw) - B.begin();
         res += sum[oidx-1] - sum[nidx-1];
         res -= oidx * od;
         res += nidx * nw;
      }
      else{
         ll oidx = upper_bound(B.begin()+1, B.begin()+n+1, od) - B.begin() - 1;
         ll nidx = upper_bound(B.begin()+1, B.begin()+n+1, nw) - B.begin() - 1;
         res -= sum[nidx] - sum[oidx];
         res -= oidx * od;
         res += nidx * nw;
      }
      cout << res << "\n";
   }
   return 0;
}
