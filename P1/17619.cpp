#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll N, Q;
pair<pll, ll> A[200000];
pll B[200000];
ll P[200000];

ll find_(ll a){
   if(a == P[a])  return a;
   return P[a] = find_(P[a]);
}

void union_(ll a, ll b){
   a = find_(a);
   b = find_(b);
   P[b] = a;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> Q;
   for(int i=1; i<=N; i++) P[i] = i;
   for(ll i=1; i<=N; i++){
      ll a;
      cin >> A[i].ff.ff >> A[i].ff.ss >> a;
      A[i].ss = i;
   }
   for(ll i=1; i<=Q; i++){
      cin >> B[i].ff >> B[i].ss;
   }

   sort(A+1, A+N+1);
   ll r = A[1].ff.ss;
   ll n = A[1].ss;

   for(ll i=2; i<=N; i++){
      if(A[i].ff.ff <= r){
         union_(A[i].ss, n);
         r = max(r, A[i].ff.ss);
      }
      else{
         r = A[i].ff.ss;
         n = A[i].ss;
      }
   }
   for(ll i=1; i<=Q; i++){
      if(find_(B[i].ff) == find_(B[i].ss)){
         cout << 1 << "\n";
      }
      else  cout << 0 << "\n";
   }

   return 0;
}
