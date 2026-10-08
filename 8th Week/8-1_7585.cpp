#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;

int N;
char S[300];

int main()
{
  while(true)
  {
    stack<char> s;
    fgets(S, 256, stdin);
    N = strlen(S);
    S[N - 1] = '\0';
    N--;
    if(strcmp(S, "#") == 0)
      break;

    bool flag = false;
    for(int i = 0; i < N; i++)
    {
      if(S[i] == '(' || S[i] == '{' || S[i] == '[')
      {
        s.push(S[i]);
      }
      else if(S[i] == ')'){
        if(s.top() == '(') s.pop();
        else  break;
      }
      else if(S[i] == '}'){
        if(s.top() == '{') s.pop();
        else  break;
      }
      else if(S[i] == ']'){
        if(s.top() == '[') s.pop();
        else  break;
      }
    }
    if(s.empty())
      flag = true;

    if(flag)
      printf("Legal\n");
    else
      printf("Illegal\n");
  }
}
