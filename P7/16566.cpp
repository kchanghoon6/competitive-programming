#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N, M, K;
ll A[5000000];
ll B[5000000];
ll P[5000000];

ll find_(ll a){
   if(a == P[a])  return a;
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
   cout.tie(0);
   cin >> N >> M >> K;

   for(ll i=1; i<=M; i++)   cin >> A[i];
   sort(A+1, A+M+1);
   for(ll i=1; i<=M+1; i++) P[i] = i;
   for(ll i=1; i<=K; i++){
      ll p;
      cin >> p;
      ll idx = upper_bound(A+1, A+M+1, p)-A;
      idx = find_(idx);
      cout << A[idx] << "\n";
      P[idx] = find_(idx+1);
   }
   return 0;
}
