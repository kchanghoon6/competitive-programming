// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//    int N;
//    int arrive[10000][2];
//    scanf("%d", &N);
//    for(int i=0; i<N; i++){
//       scanf("%d %d", &arrive[i][0], &feed[i][1]);
//    }
//    int arrive_sort[10000][2];
//    int feed_sort[10000];
//    int wait = 0;
//    int wait_max = 0;

//    queue <int> q;
//    copy(begin(arrive), end(arrive), begin(arrive_sort));
//    sort(arrive_sort, arrive_sort+N);

//    for(int t=arrive_sort[0]; arrive_sort[t] != '\0'; t+=feed_sort[t]){
//       for(int i=0; i<N;)

//    }

#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
int main(){
   int N;
   pair<int, int> cows[10000];
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      scanf("%d %d", &cows[i].ff, &cows[i].ss);
   }
   pair<int, int> cows_sort[10000];
   for(int i=0; i<N; i++){
      cows_sort[i].ff = cows[i].ff;
      cows_sort[i].ss = cows[i].ss;
   }
   sort(cows_sort,cows_sort+N,
      [](const pair<int,int>& a,const pair<int,int>& b){
         return a.first<b.first;
      }
      );


   return 0;
}
