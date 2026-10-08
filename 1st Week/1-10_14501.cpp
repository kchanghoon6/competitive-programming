#include <stdio.h>
#include <cmath>
static int t[20];
static int p[20];
int main(){
  int pTot;
  int pMax=0;
  int iStart = 0;
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d %d", &t[i], &p[i]);
  }
  while(iStart<n){
    pTot = 0;
    for(int i=iStart; i<n; i+=t[i]){
      if(i+t[i]<n){
        pTot += p[i];
        if(i+t[i]+t[i+t[i]]>n){
          if(pMax<pTot) pMax = pTot;
        }
      }
      else{
        i = i - t[i] + 1;
      }
    }
  }

}
