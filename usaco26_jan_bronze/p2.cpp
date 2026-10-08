#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, k;
ll A[500000];
ll tr(string str){
   if(str == "COW")    return 0;
   if(str == "OWC")    return 1;
   if(str == "WCO")    return 2;
   return 0;
}
char remove(ll a, ll b){
   if(a == b)  return 'C';

   ll s = min(a, b);
   ll e = max(a, b);
   if(s == 0 && e == 1) return 'C';
   if(s == 1 && e == 2) return 'O';
   if(s == 0 && e == 2) return 'W';
   return 'C';
}
ll position(string str, char c){
   for(ll i=0; i<3; i++){
      if(str[i] == c){
         return i;
      }
   }
   return 0;
}


int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);



   cin >> t >> k;
   while(t--){
      ll n;
      string str;
      cin >> n;
      cin >> str;
      ll len = 3*n;
      if(n%2){
         cout << "-1\n";
         continue;
      }
      ll flag = 1;
      for(ll i=0; i<len/2; i++){
         if(str[i] != str[i+len/2]){
            flag = 0;
            break;
         }
      }
      if(flag){
         cout << "1\n";
         for(ll i=0; i<len; i++){
            cout << "1";
            if(i != len-1){
               cout << " ";
            }
         }
         cout << "\n";
         continue;
      }
      for(ll i=0; i<n/2; i++){
         ll sa = 3*i;
         ll sb = 3*(i+n/2);

         string s1 = str.substr(sa, 3);
         string s2 = str.substr(sb, 3);
         ll a = tr(s1);
         ll b = tr(s2);

         char ch = remove(a, b);
         ll c = position(s1, ch);
         ll d = position(s2, ch);

         for(ll j=0; j<3; j++){
            if(j == c)  A[sa+j] = 1;
            else    A[sa+j] = 2;
         }
         for(ll j=0; j<3; j++){
            if(j == d)  A[sb+j] = 1;
            else    A[sb+j] = 2;
         }
      }
      cout << "2\n";
      for(ll i=0; i<len; i++){
         cout << A[i];
         if(i != len-1){
            cout << " ";
         }
      }
      cout << "\n";
   }


   return 0;
}
