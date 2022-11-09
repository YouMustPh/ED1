#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcpy1(char *dest, char *src)
{
  int i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

char *strcpy2(char *src)
{
  int i = 0;
  while (src[i] != '\0')
  {
    i++;
  }
  char *dest = malloc(i * sizeof(char));
  for (int j = 0; j < i; j++)
  {
    dest[j] = src[j];
  }

  dest[i] = '\0';

  return dest;
}

int main()
{
  char str[] = "Change me";
  char str1[] = "Hello World";
  char str2[] = "World Hello";

  strcpy1(str, str1);
  printf("%s\n", str);
  printf("%s\n", str1);

  char *str3 = strcpy2(str2);
  printf("%s\n", str2);
  printf("%s\n", str3);

  free(str3);
  str3 = NULL;

  return 0;
}