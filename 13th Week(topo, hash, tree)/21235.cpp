#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> A;

int animal_num(string s){
   if(s.find("Rat") != string::npos) return 11;
   if(s.find("Ox") != string::npos) return 0;
   if(s.find("Tiger") != string::npos) return 1;
   if(s.find("Rabbit") != string::npos) return 2;
   if(s.find("Dragon") != string::npos) return 3;
   if(s.find("Snake") != string::npos) return 4;
   if(s.find("Horse")!= string::npos) return 5;
   if(s.find("Goat") != string::npos) return 6;
   if(s.find("Monkey") != string::npos) return 7;
   if(s.find("Rooster") != string::npos) return 8;
   if(s.find("Dog") != string::npos) return 9;
   if(s.find("Pig") != string::npos) return 10;
   else return -1;
}

int main(){
   int N;
   cin >> N;
   cin.ignore();
   A["Bessie"] = 0;
   for(int i=0; i<N; i++){
      string a,b,c,d; cin>>a; cin>>b; cin>>b; cin>>b;
      cin>>c; cin>>d; cin>>d; cin>>d;
      string name1 = a;
      string name2 = d;
      int n1 = animal_num(c);
      int n2 = ((A[name2]%12)+12)%12;
      int diff = ((12 +n1-n2))%12;
      diff = (diff == 0 ? 12 : diff);
      if(b == "previous"){
         if(diff!=12) A[name1] = A[name2] - 12+diff;
         else A[name1]=A[name2]-12;
      }
      else{
         A[name1] = A[name2] + diff;
      }
   }
   cout << abs(A["Elsie"]) << "\n";
   return 0;
}
