#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N;
char A[1000010];
char B[1000010];
queue<ll> C[50];
ll tree[4000040];

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
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N >> (A+1) >> (B+1);
   for(ll i=1; i<=N; i++){
      C[B[i]-'A'].push(i);
   }
   ll res = 0;
   for(ll i=1; i<=N; i++){
      ll idx = A[i]-'A';
      res += sum_(1, 1, N, C[idx].front()+1, N);
      update_(1, 1, N, C[idx].front(), 1);
      C[idx].pop();
   }
   cout << res << "\n";
   return 0;
}
