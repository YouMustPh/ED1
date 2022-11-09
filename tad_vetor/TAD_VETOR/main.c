#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tad_vetor.h"

int main()
{

  Vetor *v = vetor_criar();

  for (int i = 0; i < 10; i++)
  {
    vetor_anexar(v, i);
  }
  vetor_imprimir(v);
  printf("\n");

  int *valorRemovido = malloc(sizeof(int));
  vetor_removerPorPosicao(v, 5, valorRemovido);
  vetor_imprimir(v);
  printf("  Valor removido: %d\n", *valorRemovido);

  vetor_inserir(v, 100, 5);
  vetor_imprimir(v);
  printf("\n");

  char str[100];
  vetor_toString(v, str);
  printf("%s\n", str);

  int num = vetor_removerElemento(v, 100);
  printf("Posicao do Valor removido: %d\n", num);
  vetor_imprimir(v);

  vetor_destruir(&v);

  printf("\n");

  Vetor* vetor = vetor_importar("vetor.txt");
  vetor_imprimir(vetor);


  return 0;
}