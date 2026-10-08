#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t, edge, cycle;
ll A[100];
ll visited[100];
ll indegree[100];

ll tr(char c){
   return (c >= 'a' && c <= 'z') ? c-'a' : c-'A'+26;
}

void dfs(ll u){
   visited[u] = 1;
   ll v = A[u];
   if(v != -1 && v != u){
      edge++;
      if(visited[v] == 1){
         ll p = 1, c = v;
         while(1){
            if(indegree[c] > 1) p = 0;
            c = A[c];
            if(c == v) break;
         }
         if(p) cycle++;
      }
      else if(visited[v] == 0) dfs(v);
   }
   visited[u] = 2;
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> t;
   while(t--){
      string s1, s2;
      cin >> s1 >> s2;
      ll n = s1.size();

      memset(A, -1, sizeof(A));
      memset(visited, 0, sizeof(visited));
      memset(indegree, 0, sizeof(indegree));
      edge = 0, cycle = 0;

      ll flag = 1;
      set<ll> T;
      for(ll i=0; i<n; i++){
         ll a = tr(s1[i]), b = tr(s2[i]);
         if(A[a] == -1) A[a] = b;
         else if(A[a] != b) flag = 0;
         T.insert(b);
      }

      if(!flag || (T.size() == 52 && s1 != s2)){
         cout << "-1\n";
         continue;
      }

      for(ll i=0; i<52; i++){
         if(A[i] != -1 && A[i] != i) indegree[A[i]]++;
      }

      for(ll i=0; i<52; i++){
         if(!visited[i]) dfs(i);
      }

      cout << edge + cycle << "\n";
   }
   return 0;
}
