#include <stdio.h>
#include <string.h>

int stringLength(char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return i + 1;
}

int countCharacters(char *str)
{
  int count = 0;
  while (*str != '\0')
  {
    if (*str != ' ')
    {
      count++;
    }
    str++;
  }
  return count;
}

int countVogals(char *str)
{
  int count = 0;
  char *vogals = "aeiouAEIOU";
  while (*str != '\0')
  {
    for (int i = 0; i < 10; i++)
    {
      if (*str == vogals[i])
      {
        count++;
      }
    }
    str++;
  }
  return count;
}


void removeSpaces(char *str)
{
  int i = 0;
  int j = 0;
  while (str[i] != '\0')
  {
    if (str[i] != ' ')
    {
      str[j] = str[i];
      j++;
  printf("%s\n", str);
    }
    i++;
  }
  str[j] = '\0';
}

int main()
{

  char *str = "    teste  hendrick     gabriel   l  ";

  removeSpaces(str);

  printf("%s\n", str);

  

  return 0;
}