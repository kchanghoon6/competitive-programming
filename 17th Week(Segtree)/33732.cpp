#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll T, N;
ll A[500000];
pll tree[2000000];
vector<ll> B;

pll update_(ll idx, ll sidx, ll eidx, ll t, pll val){
   if(t < sidx || t > eidx)   return tree[idx];
   if(sidx == eidx)  return tree[idx] = val;
   ll midx = (sidx+eidx)/2;
   return tree[idx] = max(update_(2*idx, sidx, midx, t, val), update_(2*idx+1, midx+1, eidx, t, val));
}

pll max_(ll idx, ll sidx, ll eidx, ll s, ll e){
   if(s > eidx || e < sidx)   return {-1, 0};
   if(s <= sidx && e >= eidx) return tree[idx];
   ll midx = (sidx + eidx)/2;
   return max(max_(2*idx, sidx, midx, s, e), max_(2*idx+1, midx+1, eidx, s, e));
}


int main(){
   scanf("%lld", &T);
   while(T--){
      scanf("%lld", &N);
      for(ll i=1; i<=N; i++){
         scanf("%lld", &A[i]);
         update_(1, 1, N, i, {A[i], i});
      }
      ll L = 1, R = N;
      ll move = 0;
      while(L <= R){
         pll k = max_(1, 1, N, L, R);
         update_(1, 1, N, k.ss, {-1, k.ss});
         B.push_back(k.ff);
         if(L == 1 && R == N){
            L = k.ss+1;
            continue;
         }
         if(k.ss > L && !move){
            move = 1;
            update_(1, 1, N, k.ss, {-1e15, k.ss});
         }
         else{
            L = k.ss+1;
         }
      }
      for(auto i : B){
         printf("%lld ", i);
      }
      printf("\n");
      B.clear();
      for(ll i=1; i<=N; i++){
         A[i] = 0;
      }
      for(ll i=1; i<=1900000; i++){
         tree[i] = {0, 0};
      }
   }

   return 0;
}
