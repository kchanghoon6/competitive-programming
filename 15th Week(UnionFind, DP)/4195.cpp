#include <bits/stdc++.h>
#define ll long long
#define pll pair<string, ll>
#define ff first
#define ss second
using namespace std;

ll T, F;
unordered_map<string, pll> P;

string find_(string a){
   if(P[a].ff == a)  return a;
   return P[a].ff = find_(P[a].ff);
}
void union_(string a, string b){
   a = find_(a);
   b = find_(b);
   if(a == b)  return;
   P[a].ss += P[b].ss;
   P[b].ff = a;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> T;
   while(T--){
      cin >> F;
      P.clear();
      for(ll i=0; i<F; i++){
         string a, b;
         cin >> a >> b;
         if(P.find(a) == P.end())  P[a] = {a, 1};
         if(P.find(b) == P.end())  P[b] = {b, 1};
         union_(a, b);
         cout << P[find_(b)].ss << "\n";
      }
   }
   return 0;
}
