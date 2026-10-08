#include <bits/stdc++.h>
using namespace std;

int sp[300005][19];
int lg[300005];

void build_sparse(int n){
   for(int i=2; i<=n; i++) lg[i] = lg[i/2] + 1;
   for(int j=1; j<19; j++){
      for(int i=1; i+(1<<j)-1<=n; i++){
         sp[i][j] = max(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
      }
   }
}

int query(int l, int r){
   if(l > r) return 0;
   int k = lg[r-l+1];
   return max(sp[l][k], sp[r-(1<<k)+1][k]);
}

int c[300005];
int req_pfx[300005];

int main(){
   int T;
   scanf("%d", &T);
   while(T--){
      int N, Q, C;
      scanf("%d %d %d", &N, &Q, &C);
      for(int i=1; i<=N; i++){
         scanf("%d", &c[i]);
         sp[i][0] = c[i];
         req_pfx[i] = 0;
      }
      build_sparse(N);

      vector<pair<int,int>> pairs(Q);
      vector<vector<int>> at_start(N+2), at_end_idx(N+2);
      for(int i=0; i<Q; i++){
         int a, h;
         scanf("%d %d", &a, &h);
         pairs[i] = {a, h};
         at_start[a].push_back(i);
         at_end_idx[h].push_back(i);
      }

      for(int i=0; i<Q; i++){
         int a = pairs[i].first, h = pairs[i].second;
         int flat_max = query(a+1, h-1);
         req_pfx[a] = max(req_pfx[a], flat_max);
      }

      bool fail = false;
      int cur_pfx = 0, req = 0;
      multiset<int> active;
      vector<int> snap(Q, 0);

      for(int i=1; i<=N; i++){
         int lb = 1, ub = C;

         // 끝나는 구간의 최댓값보다 커야 함
         for(int idx : at_end_idx[i]){
            lb = max(lb, snap[idx] + 1);
            active.erase(active.find(snap[idx]));
         }

         // 진행 중인 구간의 상한
         if(!active.empty())
            ub = min(ub, *active.begin());

         // 필요한 누적 최댓값
         req = max(req, req_pfx[i]);
         if(cur_pfx < req)
            lb = max(lb, req);

         // 현재 값 결정
         if(c[i] != 0){
            if(c[i] < lb || c[i] > ub){ fail = true; break; }
         } else{
            if(lb > ub || lb > C){ fail = true; break; }
            c[i] = lb;
         }
         cur_pfx = max(cur_pfx, c[i]);

         // 시작하는 구간의 누적 최댓값 저장
         for(int idx : at_start[i]){
            snap[idx] = cur_pfx;
            active.insert(cur_pfx);
         }
      }

      if(fail) printf("-1\n");
      else{
         for(int i=1; i<=N; i++)
            printf("%d%c", c[i], i==N ? '\n' : ' ');
      }
   }
   return 0;
}
