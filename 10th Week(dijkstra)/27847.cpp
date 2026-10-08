#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll g, n;
tuple<ll, ll, ll> G[200000];  // x, y, t
ll N[200000][3];
int cnt;

ll lb_time(ll nt){
   ll s = 0, e = g-1;
   ll result = -1;
   while(s <= e){
      ll mid = (s+e)/2;
      if(get<0>(G[mid]) <= nt){
         result = mid;
         s = mid + 1;
      }
      else{
         e = mid - 1;
      }
   }
   return result;
}


ll ub_time(ll nt){
   ll s = 0, e = g-1;
   ll result = g;
   while(s <= e){
      ll mid = (s+e)/2;
      if(get<0>(G[mid]) >= nt){
         result = mid;
         e = mid - 1;
      }
      else{
         s = mid + 1;
      }
   }
   return result;
}

int main(){
   scanf("%lld %lld", &g, &n);
   for(int i=0; i<g; i++){
      ll x, y, t;
      scanf("%lld %lld %lld", &x, &y, &t);
      G[i] = {t, x, y};
   }
   for(int i=0; i<n; i++){
      scanf("%lld %lld %lld", &N[i][0], &N[i][1], &N[i][2]);
   }
   sort(G, G+g);

   for(int i=0; i<n; i++){
      ll lb = lb_time(N[i][2]); // idx
      ll ub = ub_time(N[i][2]);
      bool reach_prev = (lb == -1);
      bool reach_fut = (ub == g);

      if(ub < g){
         ll time_diff = get<0>(G[ub]) - N[i][2];
         ll dx = abs(get<1>(G[ub]) - N[i][0]);
         ll dy = abs(get<2>(G[ub]) - N[i][1]);
         ll dist = dx*dx + dy*dy;
         if(time_diff * time_diff >= dist){
            reach_fut = true;
         }
      }
      if(lb != -1){
         ll time_diff = N[i][2] - get<0>(G[lb]);
         ll dx = abs(get<1>(G[lb]) - N[i][0]);
         ll dy = abs(get<2>(G[lb]) - N[i][1]);
         ll dist = dx*dx + dy*dy;
         if(time_diff * time_diff >= dist){
            reach_prev = true;
         }
      }
      if(!(reach_fut && reach_prev)){
         cnt++;
      }
   }
   printf("%d\n", cnt);
   return 0;
}
