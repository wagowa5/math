#include <stdio.h>

#define N 3

void make_line(int X[][2][2], int L[][2][2], int i) {
  
  //printf("[%d/%d,%d/%d]\n",X[i][0][1],X[i][0][0],X[i][1][1],X[i][1][0]);
  L[i][0][0] = X[i][0][1]*X[i][1][0];
  L[i][0][1] = X[i][0][0]*X[i][1][1];
  L[i][1][0] = 1;
  L[i][1][1] = -1;

  printf("Line[%d] = %d/%d x + %d/%d y\n",i ,L[i][0][1],L[i][0][0],L[i][1][1],L[i][1][0]);
  
}

int check_line(int X[][2][2], int L[][2][2], int i) {
  int ineq = 1;
  int ch[2];
  int f1 = 0;
  int f2 = 0;
  int j;

  for(j = 0; j < N; j++) {
    ch[0] = L[i][0][0]*L[i][1][0]*X[j][0][0]*X[j][1][0];
    ch[1] = L[i][0][1]*L[i][1][0]*X[j][1][0]*X[j][0][1] + L[i][1][1]*L[i][0][0]*X[j][0][0]*X[j][1][1];

    //printf("ch:%d/%d\n",ch[1],ch[0]);
    if((double)(ch[1]/ch[0]) <= 0) {
      f1--;
    }
    if((-1)*f1 == N) {
      return f1/N;
    }

    if((double)(ch[1]/ch[0]) >= 0) {
      f2++;
      //printf("X[%d],f2 : %d\n",j,f2);
    }
    if(f2 == N) {
      return f2/N;
    }
  }

  return 0;
}

int main(void)
{
  int X[N][2][2] =
    {{{1,1},{1,1}},
     {{1,1},{1,4}},
     {{1,4},{1,1}}};
  int Line[N][2][2] = {1};
  int Hsp[N] = {0};
  int i;

  for(i = 0; i < N; i++) {
    make_line(X, Line, i);
  }
  for(i = 0; i < N; i++) {
    Hsp[i] = check_line(X, Line, i);
  }

  for(i = 0; i < N; i++) {
    printf("Hsp[%d] = %d\n",i,Hsp[i]);
  }

  return 0;
}
