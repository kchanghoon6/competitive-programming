#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
ll A[200000];
vector<char> B;
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> N;
   for(ll i=1; i<=N; i++){
      cin >> A[i];
   }
   ll dir = 1;
   ll idx = 1;
   while(A[idx] > 0){
      if(dir == 1)   cout << 'R';
      else  cout << 'L';
      A[idx]--;
      if(A[idx+dir] < A[idx]){
         dir = -dir;
      }
      else  idx += dir;
   }
   cout << "\n";
   return 0;
}
