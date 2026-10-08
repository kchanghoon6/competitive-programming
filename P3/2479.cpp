#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K, A, B;
ll S[2000];
vector<ll> G[2000];
ll visited[2000];
ll dd[2000];

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   cin >> N >> K;
   for(ll i=1; i<=N; i++){
      string str;
      cin >> str;

      // 이진 문자열을 정수로 변환
      S[i] = 0;
      for(ll j=0; j<K; j++){
         if(str[j] == '1'){
            S[i] |= (1LL << (K-1-j));
         }
      }
   }
   for(ll i=1; i<=N; i++){
      for(ll j=i+1; j<=N; j++){
         ll H = 0;
         ll p = S[i]^S[j];
         for(ll k=0; k<K; k++){
            if(p&(1LL<<k))   H++;
         }
         if(H == 1){
            G[i].push_back(j);
            G[j].push_back(i);
         }
      }
   }
   cin >> A >> B;
   queue<ll> q;
   q.push(A);
   visited[A] = 1;
   while(!q.empty()){
      auto v = q.front();
      q.pop();
      for(auto i : G[v]){
         if(!visited[i]){
            visited[i] = 1;
            q.push(i);
            dd[i] = v;
         }
      }
   }
   vector<ll> ans;
   if(!visited[B])   cout << "-1\n";
   else{
      ll a = B;
      ans.push_back(a);
      while(a != A){
         ans.push_back(dd[a]);
         a = dd[a];
      }
   }
   ll len = ans.size();
   for(ll i=len-1; i>=0; i--){
      cout << ans[i] << " ";
   }
   cout << "\n";



   return 0;
}
