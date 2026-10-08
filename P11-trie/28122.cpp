#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A[2000000];
ll vt[2000000][5];
ll fin[2000000];
ll sz = 1;
ll ans = 0;


void insert_(ll a){
   ll idx = 1;
   for(ll i=0; i<60; i++){
      ll k = (a>>i)&1LL;
      if(vt[idx][k] == 0)  vt[idx][k] = ++sz;
      idx = vt[idx][k];
   }
   fin[idx]++;
}

void DFS(ll idx, ll d, ll cnt){
   ans = max(ans, cnt);
   if(d == 60) return;
   if(fin[idx]){
      fin[idx]--;
      if(vt[idx][0]) DFS(vt[idx][0], d+1, cnt+1);
      if(vt[idx][1]) DFS(vt[idx][1], d+1, cnt+1);
      fin[idx]++;
   }
   if(vt[idx][0]) DFS(vt[idx][0], d, cnt);
   if(vt[idx][1]) DFS(vt[idx][1], d, cnt);
}



ll N;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N;
   for(ll i=0; i<N; i++){
      cin >> A[i];
      insert_(A[i]);
   }
   DFS(1, 0, 0);
   cout << ans << "\n";

   return 0;
}
