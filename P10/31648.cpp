#include <bits/stdc++.h>
#define ll long long
using namespace std;



ll T;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> T;
   while(T--){
      string str;
      cin >> str;
      if(str.back() == '0')   cout << "E" << "\n";
      else  cout << "B" << "\n";
   }
   return 0;
}
