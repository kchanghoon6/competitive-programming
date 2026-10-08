#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

vector<pair<ll, bool>> v;
int main(){
   ll N, a, b;
   cin >> N >> a >> b;
   for(int i=0; i<N; i++){
      ll c;
      string d;
      bool e;
      cin >> d >> c;
      if(d=="NS") e = false;
      if(d=="S") e = true;
      v.push_back({c, e});
   }
   sort(v.begin(), v.end());
   ll cnt_S = 0;
   ll len_v = v.size();

   for(ll i=0; i<len_v-1; i++){
      ll left = v[i].ff;
      ll right = v[i+1].ff;
      ll mid
   }
   printf("%lld\n", cnt_S);
   return 0;
}
