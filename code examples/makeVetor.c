#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *makeVetor1(int n, int fill)
{
  int *v = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    v[i] = fill;
  }

  return v;
}

void makeVetor2(int n, int fill, int **v)
{
  *v = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    (*v)[i] = fill;
  }
}

int main()
{
  int *v1, *v2;

  v1 = makeVetor1(5, -1);

  makeVetor2(5, 0, &v2);

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", v1[i]);
  }

  printf("\n");

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", v2[i]);
  }

  free(v1);
  free(v2);
  v1 = NULL;
  v2 = NULL;

  return 0;
}