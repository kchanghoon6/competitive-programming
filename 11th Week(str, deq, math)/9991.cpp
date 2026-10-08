#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int W, N;
pair<string, int> dict[1100000];
string S[20000];
int K[20000];

int main(){
   cin >> W >> N;
   for(int i=0; i<W; i++){
      cin >> dict[i].ff;
      dict[i].ss = i+1;
   }
   for(int i=0; i<N; i++){
      cin >> K[i] >> S[i];
   }
   sort(dict, dict+W);

   for(int i=0; i<N; i++){
      int s = 0, e = W-1;
      int lb = W;
      while(s <= e){
         int mid = (s+e)/2;
         if(dict[mid].ff.substr(0, S[i].length()) >= S[i]){
            lb = mid;
            e = mid - 1;
         }
         else{
            s = mid + 1;
         }
      }
      int ub = -1;
      s = 0, e = W-1;
      while(s <= e){
         int mid = (s+e)/2;
         if(dict[mid].ff.substr(0, S[i].length()) <= S[i]){
            ub = mid;
            s = mid + 1;
         }
         else{
            e = mid - 1;
         }
      }
      if(lb <= ub && lb+K[i]-1 <= ub){
         printf("%d\n", dict[lb+K[i]-1].ss);
      }
      else{
         printf("-1\n");
      }
   }
   return 0;
}
