#include <stdio.h>

struct Hsp {
  int c[2][2];
  int ineq;  //1なら≧,-1なら≦
};

struct cone {
  int p[2][2]; //x,y
};


struct Hsp *new_H(void) {
  struct Hsp *h;
  
  h = (struct Hsp *)malloc(sizeof(struct Hsp));
  h -> c[0][0] = 1;
  h -> c[0][1] = 1;
  h -> c[1][0] = 1;
  h -> c[1][1] = 1;
  h -> ineq = 1;
  
  return(h);
}

	
void print_H(struct Hsp *h) {
  int i;
  int n;
  
  n = 2;
  
  printf("[");
  for (i=0; i<n; i++) {
    printf("%d/%d,",h->c[i][1],h->c[i][0]);
  }
  printf("(%d)]",h->ineq);
  printf("\n");
}

void sort(double *array[], int n)
{
  int i, j;
  int t,tt;

  for(i = 0; i < n; i++) {
    for(j = i+1; j < n; j++) {
      if(array[0][j] > array[0][j]) {
        t = array[0][i];
	tt = array[1][i];
        array[0][i] = array[0][j];
	array[1][i] = array[1][j];
	array[0][j] = t;
	array[1][j] = tt;
      }
    }
  }

}


int main(void)
{
  struct Hsp *h1;
  struct Hsp *h2;
  int X[3][2][2] =
    {{{1,1},{1,1}},
     {{1,1},{1,4}},
     {{1,4},{1,1}}};
  int XS[3][2];
  int i,j;
  double temp[2][3];
  
  h1 = new_H();
  h1->c[0][0] = 1;
  h1->c[0][1] = -1;
  h1->c[1][0] = 1;
  h1->c[1][1] = 1;
  h1->ineq = -1;
  
  h2 = new_H();
  h2->c[0][0] = 2;
  h2->c[0][1] = -1;
  h2->c[1][0] = 1;
  h2->c[1][1] = 1;
  h2->ineq = 1;
  
  print_H(h1);
  print_H(h2);
  puts("");

  printf("cone:\n");
  for(i = 0; i < 3; i++) {
    printf("[");
    for(j = 0; j < 2; j++) {
      if(j != 1) printf("%d/%d,",X[i][j][1],X[i][j][0]);
      else printf("%d/%d",X[i][j][1],X[i][j][0]);
    }
    printf("],");
  }
  printf("\n");

  
  printf("slope:\n");
  for(i = 0; i < 3; i++) {
    XS[i][0] = X[i][1][0]*X[i][0][1];
    XS[i][1] = X[i][1][1]*X[i][0][0];
    temp[0][i] = (double)(XS[i][1]) / (double)(XS[i][0]);
    temp[1][i] = i;
  }
  
  sort(temp,3);
  for(i = 0; i < 3; i++) {
    printf("[%f,%d],",temp[0][i],(int)(temp[1][i]));
  }
  puts("");
  
  
  return 0;
}
