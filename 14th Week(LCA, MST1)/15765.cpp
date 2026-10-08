#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

ll N;
map<string, vector<string>> A;
map<string, string> P;
map<string, ll> D;
map<string, ll> tree_num;
map<string, ll> visited;

void make_tree(string node, string par, ll num){            // tree number!!
   visited[node] = 1;
   tree_num[node] = num;
   P[node] = par;
   if(par == "") D[node] = 0;
   else  D[node] = D[par]+1;
   for(auto i : A[node]){
      if(i == par)   continue;
      make_tree(i, node, num);
   }
}
string lca(string u, string v){
   if(tree_num[u] != tree_num[v]){
      return "NOT RELATED";
   }
   if(D[u] < D[v])   swap(u, v);
   string str;
   ll depth = 0;
   if(D[u] == D[v] && P[u] == P[v]){
      return "SIBLINGS";
   }
   while(D[u] > D[v]){
      u = P[u];
      depth++;
   }
   if(u == v){
      for(ll i=3; i<=depth; i++){
         str += "great-";
      }
      if(depth >= 2) str += "grand-";
      return str+"mother";
   }
   if(P[v] == P[u]){
      for(ll i=2; i<=depth; i++){
         str += "great-";
      }
      return str+"aunt";
   }
   return "COUSINS";
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   string x, y;
   cin >> N >> x >> y;
   set<string> nodes, children;
   for(ll i=0; i<N; i++){
      string a, b;
      cin >> a >> b;
      A[a].push_back(b);
      nodes.insert(a);
      nodes.insert(b);
      children.insert(b);
   }
   ll num = 0;
   for(auto i : nodes){
      if(visited[i] == 0 && children.count(i) == 0)
         make_tree(i, "", num++);
   }
   string result = lca(y, x);
   if(result == "NOT RELATED" || result == "SIBLINGS" || result == "COUSINS"){
      cout << result << "\n";
   }
   else{
      if(D[y] < D[x])   cout << y << " is the " << result << " of " << x << "\n";
      else     cout << x << " is the " << result << " of " << y << "\n";
   }
   return 0;
}
