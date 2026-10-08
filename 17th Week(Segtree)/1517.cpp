#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N;
pll A[600000];
ll P[600000];
ll L[600000];
ll tree[2000000];

ll update_(ll idx, ll sidx, ll eidx, ll t, ll  val){
   if(t < sidx || t > eidx)   return tree[idx];
   if(sidx == eidx)  return tree[idx] += val;
   ll midx = (sidx + eidx)/2;
   return tree[idx] = update_(2*idx, sidx, midx, t, val) + update_(2*idx+1, midx+1, eidx, t, val);
}

ll sum_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return 0;
   if(s <= sidx && e >= eidx) return tree[idx];
   ll midx = (sidx + eidx)/2;
   return sum_(2*idx, sidx, midx, s, e) + sum_(2*idx+1, midx+1, eidx, s, e);
}

int main(){
   scanf("%lld", &N);
   for(ll i=1; i<=N; i++){
      scanf("%lld", &A[i].ff);
      A[i].ss = i;
   }
   sort(A+1, A+N+1);
   for(ll i=1; i<=N; i++){
      P[A[i].ss] = i;
   }
   ll result = 0;
   for(ll i=1; i<=N; i++){
      result += sum_(1, 1, N, P[i]+1, N);
      update_(1, 1, N, P[i], 1);
   }
   printf("%lld\n", result);
   return 0;
}
