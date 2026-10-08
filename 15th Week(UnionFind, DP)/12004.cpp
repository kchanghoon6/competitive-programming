#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;

vector<ll> A[100000];
ll X[100000];
ll P[100000];
ll closed[100000];
vector<string> B;

ll find_(ll a){
   if(P[a] == a) return a;
   return P[a] = find_(P[a]);
}
void union_(ll a, ll b){
   a = find_(a);
   b = find_(b);
   P[a] = b;
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N >> M;
   for(ll i=1; i<=N; i++){
      P[i] = i;
   }
   for(ll i=1; i<=M; i++){
      ll u, v;
      cin >> u >> v;
      A[u].push_back(v);
      A[v].push_back(u);
   }
   for(ll i=1; i<=N; i++){
      cin >> X[i];
      closed[X[i]] = 1;
   }
   for(ll i=N; i>=1; i--){
      ll x = X[i];
      closed[x] = 0;
      for(auto j : A[x]){
         if(closed[j])  continue;
         union_(x, j);
      }
      bool flag = 0;
      for(ll i=1; i<=N; i++){
         if(closed[i])  continue;
         if(find_(i) != find_(x)){
            B.push_back("NO");
            flag = 1;
            break;
         }
      }
      if(!flag)   B.push_back("YES");
   }
   reverse(B.begin(), B.end());
   for(auto i : B){
      cout << i << "\n";
   }

   return 0;
}
