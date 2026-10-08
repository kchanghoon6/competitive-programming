#include <stdio.h>
int N, M; // 기타 개수, 곡의 개수
int mini=11;
char G[15][100];
char A[15][55];
bool used[15];
int max_y = -1;
void backtrack(int i){
  if(i==N){
    int sum = 0;
    int num = 0;
    bool used2[55] = { false, };
    for(int k=0; k<N; k++){
      if(used[k]){
        sum++;
        for(int l=0; l<M; l++){
          if(A[k][l] == 'Y')
            used2[l] = true;
        }
      }
    }
    for(int k=0; k<M; k++){
      if(used2[k])
        num++;
    }
    if(max_y<=num){
      max_y = num;
      if(mini>sum){
        mini=sum;
      }
    }
    return;
  }
  used[i] = true;
  backtrack(i+1);
  used[i] = false;
  backtrack(i+1);
}


int main(){
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++){
    scanf("%s %s", G[i], A[i]);
  }
  backtrack(0);
  if(mini==0)    printf("-1\n");
  else    printf("%d\n", mini);
}
