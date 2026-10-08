#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, M;
vector<ll> L[5000];
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> M;
   for(ll i=0; i<N; i++){
      for(ll j=0; j<=i; j++){
         char a;
         cin >> a;
         if(a == 'W')   L[j].push_back(i);
         if(a == 'L')   L[i].push_back(j);
      }
   }
   for(ll i=0; i<N; i++){
      sort(L[i].begin(), L[i].end());
   }
   for(ll i=0; i<M; i++){
      ll a, b;
      cin >> a >> b;
      a--; b--;
      ll cnt = 0;
      for(auto j : L[a]){
         ll idx = lower_bound(L[b].begin(), L[b].end(), j)-L[b].begin();
         if(idx == L[b].size())  continue;
         if(L[b][idx] == j)   cnt++;
      }
      cout << cnt * (2*N - cnt) << "\n";
   }

   return 0;
}
