#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

unordered_map<string, ll> A;
int main(){
   ll N;
   cin.tie(0);
   cout.tie(0);
   cin >> N;
   ll cnt = 0;
   for(ll i=0; i<N; i++){
      string a, b;
      cin >> a >> b;
      if(a.substr(0, 2) != b){
         A[a.substr(0, 2)+b]++;
      }
   }
   for(auto i : A){
      string str = i.ff.substr(2, 2) + i.ff.substr(0, 2);
      if(A.find(str) != A.end()){
         cnt += i.ss * A[str];
      }
   }
   printf("%d\n", cnt/2);



   return 0;
}
