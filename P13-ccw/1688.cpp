#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

pll A[20000];
pll B[10];
ll n;
ll ccw(pll a, pll b, pll c){
   ll det = (b.ff-a.ff)*(c.ss-a.ss)-(c.ff-a.ff)*(b.ss-a.ss);
   if(det > 0) return 1;
   if(det < 0) return -1;
   else  return 0;
}
ll overlap(pll a, pll b, pll c, pll d){
   if(max(a.ff, b.ff) < min(c.ff, d.ff))  return 0;
   if(max(a.ss, b.ss) < min(c.ss, d.ss))  return 0;
   if(min(a.ff, b.ff) > max(c.ff, d.ff))  return 0;
   if(min(a.ss, b.ss) > max(c.ss, d.ss))  return 0;
   return 1;
}

ll interject(pll a, pll b, pll c, pll d){
   ll d1 = ccw(a, b, c);
   ll d2 = ccw(a, b, d);
   ll d3 = ccw(c, d, a);
   ll d4 = ccw(c, d, b);
   if(d1*d2 <= 0 && d3*d4 <= 0){
      if(!d1 && !d2 && !d3 && !d4){
         return overlap(a, b, c, d);
      }
      return 1;
   }
   return 0;
}
ll on_line(pll a, pll b, pll c){
   if(ccw(b, c, a) != 0)   return 0;
   if(a.ff < min(b.ff, c.ff) || a.ff > max(b.ff, c.ff) ||
      a.ss < min(b.ss, c.ss) || a.ss > max(b.ss, c.ss)){
      return 0;
   }
   return 1;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin >> n;
   for(ll i=0; i<n; i++){
      cin >> A[i].ff >> A[i].ss;
   }
   for(ll i=0; i<3; i++){
      ll x, y;
      cin >> x >> y;
      ll sum = 0;
      ll res = 0;
      for(ll j=0; j<n; j++){
         ll k = (j+1)%n;
         res = on_line({x, y}, A[j], A[k]);
         if(res){
            cout << "1\n";
            break;
         }
         sum += interject({x, y}, {(ll)1e10, y+1}, A[j], A[k]);
      }
      if(res)  continue;
      if(sum%2)   cout << "1\n";
      else  cout << "0\n";
   }
   return 0;
}
