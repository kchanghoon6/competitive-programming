#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


ll ccw(pll a, pll b, pll c){
   ll det = (b.ff-a.ff)*(c.ss-a.ss)-(c.ff-a.ff)*(b.ss-a.ss);
   if(det > 0) return 1;
   else if(det < 0)  return -1;
   return 0;
}
ll overlap(pll a, pll b, pll c, pll d){
   if(max(a.ff, b.ff) < min(c.ff, d.ff))  return 0;
   if(max(a.ss, b.ss) < min(c.ss, d.ss))  return 0;
   if(min(a.ff, b.ff) > max(c.ff, d.ff))  return 0;
   if(min(a.ss, b.ss) > max(c.ss, d.ss))  return 0;
   return 1;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   pll a, b, c, d;

   cin >> a.ff >> a.ss >> b.ff >> b.ss;
   cin >> c.ff >> c.ss >> d.ff >> d.ss;

   ll d1 = ccw(a, b, c);
   ll d2 = ccw(a, b, d);
   ll d3 = ccw(c, d, a);
   ll d4 = ccw(c, d, b);

   if(d1*d2 <= 0 && d3*d4 <= 0){
      if(!d1 && !d2 && !d3 && !d4){
         cout << overlap(a, b, c, d) << "\n";
      }
      else  cout << "1\n";
   }
   else  cout << "0\n";

   return 0;
}
