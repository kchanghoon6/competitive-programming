#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll N, K;
ll A[200000];
ll tree[800000];

ll update_(ll idx, ll sidx, ll eidx, ll t, ll  val){
   if(t < sidx || t > eidx)   return tree[idx];
   if(sidx == eidx){
      return tree[idx] = val;
   }
   ll midx = (sidx + eidx)/2;
   return tree[idx] = update_(2*idx, sidx, midx, t, val) + update_(2*idx+1, midx+1, eidx, t, val);
}

ll find_(ll idx, ll sidx, ll eidx, ll k){
   if(sidx == eidx) return sidx;
   ll midx = (sidx + eidx)/2;
   if(tree[2*idx] >= k) return find_(2*idx, sidx, midx, k);
   else  return find_(2*idx+1, midx+1, eidx, k-tree[2*idx]);
}

int main(){
   scanf("%lld %lld", &N, &K);
   for(ll i=1; i<=N; i++){
      update_(1, 1, N, i, 1);
   }
   ll p = 0;
   printf("<");
   for(ll i=1; i<=N; i++){
      p += K-1;
      p %= N-i+1;
      ll a = find_(1, 1, N, p+1);
      update_(1, 1, N, a, 0);
      printf("%lld", a);
      if(i < N)   printf(", ");
   }
   printf(">\n");
   return 0;
}
