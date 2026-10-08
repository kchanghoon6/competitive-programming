#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pll pair<int, int>
using namespace std;

ll T;

int main(){
   scanf("%lld", &T);
   while(T--){
      ll a;
      scanf("%lld", &a);
      ll digit = 0;
      for(ll i=a; i>=1; i/=10){
         digit++;
      }
      digit++;
      ll lb = 0;
      ll ub = 0;
      for(ll i=digit; i>=1; i--){
         ll b = 1;
         for(ll j=0; j<i; j++){
            b *= 10;
         }
         lb += 4*b;
         if(i==digit)   ub += 4*b;
         else  ub += 9*b;
      }
      lb += 5;
      ub += 9;
      ll result = 0;
      if(a < lb){

      }
   }


   return 0;
}
