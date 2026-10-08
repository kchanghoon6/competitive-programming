#include <bits/stdc++.h>
using namespace std;

char R[50];
char L[50];

void preorder(char node){
   printf("%c", node);
   if(L[node-'A'] != '.')  preorder(L[node-'A']);
   if(R[node-'A'] != '.')  preorder(R[node-'A']);
}
void inorder(char node){
   if(L[node-'A'] != '.')  inorder(L[node-'A']);
   printf("%c", node);
   if(R[node-'A'] != '.')  inorder(R[node-'A']);
}
void postorder(char node){
   if(L[node-'A'] != '.')  postorder(L[node-'A']);
   if(R[node-'A'] != '.')  postorder(R[node-'A']);
   printf("%c", node);
}

int main(){
   int N;
   scanf("%d", &N);
   for(int i=0; i<N; i++){
      char a, b, c;
      scanf(" %c %c %c", &a, &b, &c);
      L[a-'A'] = b;
      R[a-'A'] = c;
   }
   preorder('A');
   printf("\n");
   inorder('A');
   printf("\n");
   postorder('A');
   return 0;
}
