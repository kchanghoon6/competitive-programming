#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, M, K;
pll A[300000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N >> M >> K;
   for(ll i=0; i<N; i++){
      ll w, a;
      cin >> w >> a;
      A[i] = {w, a};
   }
   sort(A, A+N);
   queue<pll> q;
   ll t = 0;
   ll res = 0;
   for(auto p : A){
      ll k = 0;
      while(!q.empty() && q.front().ff <= p.ff-K){
         k += q.front().ss;
         q.pop();
      }
      ll cow = min(p.ss, k+M-t);
      res += cow;
      ll nt = max(0LL, cow-k);
      t += nt;
      if(cow > 0) q.push({p.ff, cow});
   }
   cout << res << "\n";

   return 0;
}
