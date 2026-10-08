#include <stdio.h>
int N;
int A[15];
int maxi=-1000000000;
int mini=1000000000;
void backtrack(int v, int i, int a, int b, int c, int d){
  if(a==0 && b==0 && c==0 && d==0){
    if(maxi<v)  maxi = v;
    if(mini>v)  mini = v;
    return;
  }
  if(i==0){
    backtrack(v+A[i], i+1, a, b, c, d);
  }
  if(i>0){
    if(a!=0){
      backtrack(v+A[i], i+1, a-1, b, c, d);
    }
    if(b!=0){
      backtrack(v-A[i], i+1, a, b-1, c, d);
    }
    if(c!=0){
      backtrack(v*A[i], i+1, a, b, c-1, d);
    }
    if(d!=0){
      backtrack(v/A[i], i+1, a, b, c, d-1);
    }
  }
}

int main(){
  int a, b, c, d;
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    scanf("%d ", &A[i]);
  }
  scanf("%d %d %d %d", &a, &b, &c, &d);
  backtrack(0, 0, a, b, c, d);
  printf("%d\n%d\n", maxi, mini);
}
