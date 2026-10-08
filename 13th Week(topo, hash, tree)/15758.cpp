#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pll pair<ll, ll>
using namespace std;

ll N, M;
vector<ll> A[200000];
ll B[200000];
vector<ll> C[200000];
ll indegree[200000];
queue<ll> q;
int main(){
   scanf("%lld %lld", &N, &M);
   for(int m=1; m<=M; m++){
      ll n;
      scanf("%lld", &n);
      for(ll i=1; i<=n; i++){
         scanf("%lld", &B[i]);
      }
      for(ll i=1; i<n; i++){
         A[B[i]].push_back(B[i+1]);
         indegree[B[i+1]]++;
      }
      for(ll i=1; i<=n; i++){
         if(indegree[i] == 0){
            q.push(i);
         }
      }
   }


   ll s=1, e=M;
   while(s <= e){
      ll mid = (1+M)/2;
      while(!q.empty()) q.pop();
      while(mid--){
         if(q.empty())
            while(!q.empty()){
               ll v = q.front();
               q.pop();

            }
      }
   }
   return 0;
}
