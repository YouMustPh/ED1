#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

int main()
{
  Pilha *p = pilha_criar();

  pilha_empilhar(p, 1);
  pilha_empilhar(p, 2);
  pilha_empilhar(p, 3);
  pilha_empilhar(p, 4);
  pilha_empilhar(p, 5);
  pilha_empilhar(p, 6);

  pilha_inverter(p);
  pilha_imprimir(p);

  char str[100];
  pilha_toString(p, str);
  printf("%s", str);

  pilha_destruir(&p);

  return 0;
}