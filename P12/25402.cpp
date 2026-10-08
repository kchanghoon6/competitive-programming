#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll n, q;
vector<ll> G[500000];
ll P[500000];
ll sz[500000];
ll E[500000];

ll find_(ll a){
   if(a == P[a])  return a;
   return P[a] = find_(P[a]);
}
void union_(ll a, ll b){
   a = find_(a);
   b = find_(b);
   if(a == b)  return;
   if(sz[a] < sz[b]) swap(a, b);
   P[b] = a;
   sz[a] += sz[b];
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> n;
   for(ll i=0; i<n-1; i++){
      ll a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
   }
   cin >> q;
   while(q--){
      ll k;
      set<ll> S;
      cin >> k;
      vector<ll> A;
      for(ll i=0; i<k; i++){
         ll a;
         cin >> a;
         A.push_back(a);
         sz[a] = 1;
         P[a] = a;
         E[a] = 1;
      }
      for(auto i : A){
         for(auto j : G[i]){
            if(E[j]){
               union_(i, j);
            }
         }
      }
      map<ll, ll> B;
      for(auto i : A){
         B[find_(i)]++;
      }
      ll ans = 0;
      for(auto i : B){
         ans += i.ss*(i.ss-1)/2;
      }
      cout << ans << "\n";
      for(auto i : A){
         E[i] = 0;
      }

   }



   return 0;
}
