#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll E[200000];  // enjoyment for each st point
ll D[200000];  // difficulty for each st point
ll P[200000];  // end point for each st point

ll A[200000];  // overall enjoyment for each st point
vector<ll> B[200000]; // list of difficulty on the way
ll C[200000];  // max enjoyment for each st point
vector<pll> X[100];

int main(){
   ll N, M;
   scanf("%lld", &N);
   for(ll i=2; i<=N; i++){
      scanf("%lld %lld %lld", &P[i], &D[i], &E[i]);
   }
   B[1] = vector<ll> (11, -1);
   for(ll i=2; i<=N; i++){
      A[i] += (E[i] + A[P[i]]);
      B[i] = B[P[i]];
      B[i].push_back(D[i]);
      sort(B[i].begin(), B[i].end(), greater<ll>());
      B[i].pop_back();
   }
   for(ll i=0; i<=10; i++){
      for(ll j=1; j<=N; j++){
         X[i+1].push_back({B[j][i], A[j]});
      }
      sort(X[i+1].begin(), X[i+1].end(), greater<pll>());
      for(ll j=N-2; j>=0; j--){
         X[i+1][j].ss = max(X[i+1][j].ss, X[i+1][j+1].ss);
      }
      reverse(X[i+1].begin(), X[i+1].end());
   }

   scanf("%lld", &M);
   while(M--){
      ll s, c;
      scanf("%lld %lld", &s, &c);
      ll idx = lower_bound(X[c+1].begin(), X[c+1].end(), pll{s+1, -1}) - X[c+1].begin();
      printf("%lld\n", X[c+1][idx-1].ss);
   }
   return 0;
}
