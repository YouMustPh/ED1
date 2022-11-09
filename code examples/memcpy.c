#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// memcpy(v3, v1, 2 * sizeof(int));
// memcpy(v3 + 2, v2, 3 * sizeof(int));

int *memcpy1(int *v1, int l1, int *v2, int l2)
{
  int *v3 = malloc((l1 + l2) * sizeof(int));

  int i;

  for (i = 0; i < l1; i++)
    v3[i] = v1[i];

  for (i = 0; i < l2; i++)
    v3[i + l1] = v2[i];

  return v3;
}

void memcpy2(int *v1, int l1, int *v2, int l2, int *dest) {
  for (int i = 0; i < l1; i++)
  {
    dest[i] = v1[i];
  }
  for (int i = 0; i < l2; i++)
  {
    dest[l1 + i] = v2[i];
  }
}

int main()
{
  int v1[2] = {1, 2};
  int v2[3] = {3, 4, 5};

  int *v3 = memcpy1(v1, 2, v2, 3);

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", v3[i]);
  }
  printf("\n");


  int *v4 = malloc(5 * sizeof(int));

  memcpy2(v1, 2, v2, 3, v4);

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", v4[i]);
  }
  

  free(v3);
  free(v4);
  v3 = NULL;
  v4 = NULL;

  return 0;
}