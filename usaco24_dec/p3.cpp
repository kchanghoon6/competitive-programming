#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
typedef pair<int,int> pii;

int N, Q, uc;
char G[1001][1001];
bool S[1001][1001];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
queue<pii> bq;
int qr[200001], qc[200001], ans[200001];
char qt[200001];

bool ig(int r, int c){ return r >= 1 && r <= N && c >= 1 && c <= N; }
bool ob(int r, int c){ return r == 1 || r == N || c == 1 || c == N; }

pii tg(int r, int c){
   if(G[r][c] == 'U') return {r-1, c};
   if(G[r][c] == 'D') return {r+1, c};
   if(G[r][c] == 'L') return {r, c-1};
   return {r, c+1};
}

void prop(){
   while(!bq.empty()){
      int r = bq.front().ff, c = bq.front().ss;
      bq.pop();
      for(int d = 0; d < 4; d++){
         int nr = r + dr[d], nc = c + dc[d];
         if(!ig(nr, nc) || S[nr][nc]) continue;
         if(G[nr][nc] == '?'){
            S[nr][nc] = 1; uc++;
            bq.push({nr, nc});
         } else{
            pii t = tg(nr, nc);
            if(t.ff == r && t.ss == c){
               S[nr][nc] = 1; uc++;
               bq.push({nr, nc});
            }
         }
      }
   }
}

int main(){
   ios::sync_with_stdio(0); cin.tie(0);
   cin >> N >> Q;
   for(int i = 0; i < Q; i++) cin >> qr[i] >> qc[i] >> qt[i];
   for(int r = 1; r <= N; r++)
      for(int c = 1; c <= N; c++) G[r][c] = '?';
   for(int i = 0; i < Q; i++) G[qr[i]][qc[i]] = qt[i];
   uc = 0;
   for(int r = 1; r <= N; r++)
      for(int c = 1; c <= N; c++){
         if(G[r][c] == '?' && ob(r, c)){
            S[r][c] = 1; uc++; bq.push({r, c});
         } else if(G[r][c] != '?'){
            pii t = tg(r, c);
            if(!ig(t.ff, t.ss)){
               S[r][c] = 1; uc++; bq.push({r, c});
            }
         }
      }
   prop();
   ans[Q-1] = N*N - uc;
   for(int i = Q-1; i >= 1; i--){
      G[qr[i]][qc[i]] = '?';
      if(!S[qr[i]][qc[i]]){
         bool can = ob(qr[i], qc[i]);
         if(!can)
            for(int d = 0; d < 4 && !can; d++){
               int nr = qr[i] + dr[d], nc = qc[i] + dc[d];
               if(ig(nr, nc) && S[nr][nc]) can = 1;
            }
         if(can){
            S[qr[i]][qc[i]] = 1; uc++;
            bq.push({qr[i], qc[i]});
            prop();
         }
      }
      ans[i-1] = N*N - uc;
   }
   for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
}
