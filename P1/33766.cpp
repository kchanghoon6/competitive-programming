#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll T;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin >> T;
   while(T--){
      vector<ll> A;
      ll M, K;
      cin >> M >> K;
      for(ll i=0; i<50; i++){
         ll a = 0;
         if(K & (1LL<<i)){
            a += ((1LL<<(1LL<<i))-1);
            A.push_back(a);
         }
      }
      ll sum = 0;
      for(auto i : A){
         sum += i;
      }
      if(sum > M) cout << "-1" << "\n";
      else if(sum == M){
         cout << A.size() << "\n";
         for(auto i : A){
            cout << i << " ";
         }
      }
      else{
         ll diff = M-sum;
         if(diff == 1){
            if(A[0] == 1){
               A[0]++;
            }
            else{
               cout << "-1" << "\n";
               continue;
            }
         }
         else if(diff % 2){
            A.push_back(1);
            A.push_back(2);
            diff -= 3;
            A.push_back(diff/2);
            A.push_back(diff/2);
         }
         else{
            A.push_back(diff/2);
            A.push_back(diff/2);
         }
         cout << A.size() << "\n";
         for(auto i : A){
            cout << i << " ";
         }
      }
      cout << "\n";
   }


   return 0;
}
