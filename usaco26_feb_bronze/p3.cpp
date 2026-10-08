#include <bits/stdc++.h>
#define ll long long
using namespace std;

string S[1001];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);
   ll T;
   cin >> T;
   while(T--){
      ll n, m;
      cin >> n >> m;
      string t;
      cin >> t;
      for(ll i=1; i<=n; i++) cin >> S[i];

      vector<array<ll,4>> R;
      vector<pair<ll,ll>> lc[26];
      for(ll i=2; i<=n; i++)
         for(ll j=0; j<m; j++)
            lc[S[i][j]-'a'].push_back({i, j});

      for(ll j=0; j<m; j++){
         if(S[1][j] == t[j]) continue;
         ll c = t[j] - 'a';
         bool fd = false;
         for(ll i=2; i<=n && !fd; i++){
            if(S[i][j] != t[j]) continue;
            char oc = S[1][j];
            swap(S[1][j], S[i][j]);
            R.push_back({2, 1, i, j+1});
            lc[oc-'a'].push_back({i, j});
            fd = true;
         }
         if(fd) continue;
         for(ll p=j+1; p<m && !fd; p++){
            if(S[1][p] != t[j]) continue;
            swap(S[1][j], S[1][p]);
            R.push_back({1, 1, j+1, p+1});
            fd = true;
         }
         if(fd) continue;
         while(!lc[c].empty()){
            auto [i, p] = lc[c].back();
            lc[c].pop_back();
            if(S[i][p] != t[j]) continue;
            if(p != j){
               char oc = S[i][j];
               swap(S[i][p], S[i][j]);
               R.push_back({1, i, p+1, j+1});
               lc[oc-'a'].push_back({i, p});
            }
            char oc = S[1][j];
            swap(S[1][j], S[i][j]);
            R.push_back({2, 1, i, j+1});
            lc[oc-'a'].push_back({i, j});
            fd = true;
            break;
         }
      }
      cout << R.size() << '\n';
      for(auto& r : R)
         cout << r[0] << ' ' << r[1] << ' ' << r[2] << ' ' << r[3] << '\n';
   }
   return 0;
}
