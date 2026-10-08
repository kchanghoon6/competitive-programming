#include <bits/stdc++.h>
using namespace std;

int N;
string A[200];

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
   cin.tie(0);
   cout.tie(0);
   cin >> N;
   cin.ignore();
   for(int i=0; i<N; i++){
      getline(cin, A[i]);
   }
   int yearB = 0;
   int idx = 0;
   for(int i=0; i<N; i++){
      int t = animal_num(A[i]);
      while(idx != t){
         if(A[i].find("previous") != string::npos){
            idx = (idx-1+12)%12;
            if(yearB <= 0)  yearB--;
            else  yearB++;
         }
         else{
            idx = (idx+1)%12;
            if(yearB <= 0)   yearB++;
            else  yearB--;
         }
      }
      string B;
      int j = 0;
      while(A[i][j] != ' '){
         B += A[i][j];
         j++;
      }
      if(B == "Elsie"){
         cout << abs(yearB) << "\n";
      }
   }
}
