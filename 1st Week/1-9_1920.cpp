#include <stdio.h>
#include <algorithm>
int main (){
  int n;
  int m;
  int nArr[110000];
  int mArr[110000];

  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", &nArr[i]);
  scanf("%d", &m);
  for(int i=0; i<m; i++)
    scanf("%d", &mArr[i]);

  std::sort(nArr, nArr+n);
  int start;
  int end;
  int mid;
  for(int i=0; i<m; i++){
    start = 0;
    end = n-1;
    while(true){
      mid = (start + end) / 2;
      if(mArr[i] > nArr[mid]){
        start = mid;
      }
      else if(mArr[i] < nArr[mid]){
        end = mid;
      }
      if(mArr[i] == nArr[end] || mArr[i] == nArr[start] || mArr[i] == nArr[mid]){
        printf("1\n");
        break;
      }
      if(mid+1 == end || mid-1 == start){
        printf("0\n");
        break;
      }
    }
  }
}
