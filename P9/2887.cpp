#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;


struct planet{
   ll x, y, z, idx;
};

ll N;
ll P[200000];
priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;

ll find_(ll a){
   if(P[a] == a)  return a;
   return P[a] = find_(P[a]);
}
void union_(ll a, ll b){
   a = find_(a);
   b = find_(b);
   P[b] = a;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> N;
   vector<planet> A(N+1);
   for(ll i=1; i<=N; i++){
      cin >> A[i].x >> A[i].y >> A[i].z;
      A[i].idx = i;
   }
   sort(A.begin()+1, A.end(), [](auto &a, auto &b){
      return a.x < b.x;
   });
   for(ll i=1; i<=N-1; i++){
      pq.push({A[i+1].x-A[i].x, {A[i].idx, A[i+1].idx}});
   }
   sort(A.begin()+1, A.end(), [](auto &a, auto &b){
      return a.y < b.y;
   });
   for(ll i=1; i<=N-1; i++){
      pq.push({A[i+1].y-A[i].y, {A[i].idx, A[i+1].idx}});
   }
   sort(A.begin()+1, A.end(), [](auto &a, auto &b){
      return a.z < b.z;
   });
   for(ll i=1; i<=N-1; i++){
      pq.push({A[i+1].z-A[i].z, {A[i].idx, A[i+1].idx}});
   }
   for(ll i=1; i<=N; i++)  P[i] = i;

   ll weight = 0;
   while(!pq.empty()){
      auto e = pq.top();
      pq.pop();
      if(find_(e.ss.ff) == find_(e.ss.ss))   continue;
      union_(e.ss.ff, e.ss.ss);
      weight += e.ff;
   }
   cout << weight << "\n";
   return 0;
}
