#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<string> A[200]; // 30     종류
string cow[200];
int idx[200]; // 30
int j;
int main(){
   cin >> N >> K;
   cin.ignore();
   string b;
   for(int i=0; i<N; i++){
      string a;
      getline(cin, a);
      int lb = 19;
      int ub = a.size()-5;
      cow[i] = a.substr(lb, ub-lb);
      j = 0;
      for(auto p : cow[i]){
         if(p != ' ')   b += p;
         else{
            A[j].push_back(b);
            b.clear();
            j++;
         }
      }
   }
   A[j].push_back(b);
   for(int i=0; i<=j; i++){
      sort(A[i].begin(), A[i].end());
      auto c = unique(A[i].begin(), A[i].end());
      A[i].erase(c, A[i].end());
   }
   int total = 1;
   for(int i=0; i<=j; i++){
      total *= A[i].size();
   }

   int cnt = 1;
   int i = j;
   while(cnt < K){
      if(idx[i] == A[i].size()-1){
         while(idx[i] == A[i].size()-1 && i > 0){
            i--;
         }
         idx[i]++;
         for(int k=i+1; k<=j; k++){
            idx[k] = 0;
         }
      }
      else idx[i]++;
      string str;
      for(int k=0; k<=j; k++){
         str += A[k][idx[k]];
         if(k < j)   str += " ";
      }
      bool flag = true;
      for(int k=0; k<N; k++){
         if(str == cow[k]){
            flag = false;
            break;
         }
      }
      if(flag){
         cnt++;
      }
      i = j;
   }
   for(int i=0; i<j; i++){
      cout << A[i][idx[i]] << " ";
   }
   return 0;
}
