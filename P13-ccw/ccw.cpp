#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

ll ccw(pll a, pll b, pll c){
   ll det = (b.ff-a.ff)*(c.ss-a.ss)-(b.ss-a.ss)*(c.ff-a.ff);
   if(det > 0) return 1;
   if(det < 0) return -1;
   return 0;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);




   return 0;
}
