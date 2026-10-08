#include <bits/stdc++.h>
#define ll long long
#define ub (ll)3e6
using namespace std;


ll N;
ll tree[(ll)1e7];
ll update_(ll idx, ll sidx, ll eidx, ll t, ll val){
   if(t < sidx || t > eidx)   return tree[idx];
   if(sidx == eidx) return tree[idx] += val;
   ll midx = (sidx+eidx)/2;
   return tree[idx] = update_(2*idx, sidx, midx, t, val) + update_(2*idx+1, midx+1, eidx, t, val);
}
ll find_(ll idx, ll s, ll e, ll k){
   if(s == e)  return s;
   ll mid = (s+e)/2;
   if(tree[2*idx] >= k) return find_(2*idx, s, mid, k);
   else  return find_(2*idx+1, mid+1, e, k-tree[2*idx]);
}


int main(){
   scanf("%lld", &N);
   ll n = N;
   while(N--){
      ll T, X;
      scanf("%lld %lld", &T, &X);
      if(T == 1){
         update_(1, 1, ub, X, 1);
      }
      else{
         ll val = find_(1, 1, ub, X);
         printf("%lld\n", val);
         update_(1, 1, ub, val, -1);
      }
   }

   return 0;
}
