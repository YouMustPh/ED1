#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"

void verifica(int condicao, char *mensagem)
{
  if (condicao)
  {
    printf("[OK] : %s\n", mensagem);
  }
  else
  {
    printf("Erro : %s\n", mensagem);
  }
}

void testeCriarDestruir()
{
  printf("---------------------------------------\n");
  printf("TESTE CRIAR E DESTRUIR \n");
  printf("---------------------------------------\n");

  Pilha *p = pilha_criar();
  verifica(p != NULL, "Criar pilha");
  pilha_destruir(&p);
  verifica(p == NULL, "Destruir pilha");
}

void testeEmpilharDesempilharTamanho()
{
  printf("---------------------------------------\n");
  printf("TESTE EMPILHAR E DESEMPILHAR \n");
  printf("---------------------------------------\n");

  Pilha *p = pilha_criar();
  verifica(pilha_empilhar(p, 1), "Empilhar 1");
  verifica(pilha_empilhar(p, 2), "Empilhar 2");
  verifica(pilha_empilhar(p, 3), "Empilhar 3");
  verifica(pilha_empilhar(p, 4), "Empilhar 4");
  verifica(pilha_empilhar(p, 5), "Empilhar 5");
  verifica(pilha_empilhar(p, 6), "Empilhar 6");

  verifica(pilha_tamanho(p) == 6, "Tamanho da pilha");

  TipoElemento saida;
  verifica(pilha_desempilhar(p, &saida), "Desempilhar 6");
  verifica(saida == 6, "Desempilhar 6");
  verifica(pilha_desempilhar(p, &saida), "Desempilhar 5");
  verifica(saida == 5, "Desempilhar 5");
  verifica(pilha_desempilhar(p, &saida), "Desempilhar 4");
  verifica(saida == 4, "Desempilhar 4");
  verifica(pilha_desempilhar(p, &saida), "Desempilhar 3");
  verifica(saida == 3, "Desempilhar 3");
  verifica(pilha_desempilhar(p, &saida), "Desempilhar 2");
  verifica(saida == 2, "Desempilhar 2");
  verifica(pilha_desempilhar(p, &saida), "Desempilhar 1");
  verifica(saida == 1, "Desempilhar 1");

  pilha_destruir(&p);
}

void testeTopoVazio()
{
  printf("---------------------------------------\n");
  printf("TESTE TOPO E VAZIA \n");
  printf("---------------------------------------\n");

  Pilha *p = pilha_criar();
  TipoElemento saida;

  verifica(pilha_vazia(p), "Pilha vazia");
  pilha_empilhar(p, 1);

  verifica(pilha_topo(p, &saida), "Pilha não vazia");

  pilha_destruir(&p);
}

void testeInverter()
{
  printf("---------------------------------------\n");
  printf("TESTE INVERTER \n");
  printf("---------------------------------------\n");

  Pilha *p = pilha_criar();
  pilha_empilhar(p, 1);
  pilha_empilhar(p, 2);
  pilha_empilhar(p, 3);
  pilha_empilhar(p, 4);
  pilha_empilhar(p, 5);
  pilha_empilhar(p, 6);

  pilha_inverter(p);

  TipoElemento saida;
  pilha_desempilhar(p, &saida);
  verifica(saida == 1, "Inverter 1");
  pilha_desempilhar(p, &saida);
  verifica(saida == 2, "Inverter 2");
  pilha_desempilhar(p, &saida);
  verifica(saida == 3, "Inverter 3");
  pilha_desempilhar(p, &saida);
  verifica(saida == 4, "Inverter 4");
  pilha_desempilhar(p, &saida);
  verifica(saida == 5, "Inverter 5");
  pilha_desempilhar(p, &saida);
  verifica(saida == 6, "Inverter 6");

  pilha_destruir(&p);
}

void testeToString()
{
  printf("---------------------------------------\n");
  printf("TESTE TOSTRING \n");
  printf("---------------------------------------\n");

  Pilha *p = pilha_criar();
  pilha_empilhar(p, 1);
  pilha_empilhar(p, 2);
  pilha_empilhar(p, 3);
  pilha_empilhar(p, 4);
  pilha_empilhar(p, 5);
  pilha_empilhar(p, 6);

  char str[100];
  pilha_toString(p, str);
  verifica(strcmp(str, "----\n6\n5\n4\n3\n2\n1\n----") == 0, "toString");

  pilha_destruir(&p);
}

void testeClone()
{
  printf("---------------------------------------\n");
  printf("TESTE CLONE \n");
  printf("---------------------------------------\n");

  Pilha *p = pilha_criar();
  pilha_empilhar(p, 1);
  pilha_empilhar(p, 2);
  pilha_empilhar(p, 3);
  pilha_empilhar(p, 4);
  pilha_empilhar(p, 5);
  pilha_empilhar(p, 6);

  char str[100];
  pilha_toString(p, str);

  Pilha *clone = pilha_clone(p);
  char strClone[100];
  pilha_toString(clone, strClone);

  verifica(strcmp(str, strClone) == 0, "Clone");

  pilha_destruir(&p);

  pilha_destruir(&clone);
}

void testeEmpilharTodos()
{
  printf("---------------------------------------\n");
  printf("TESTE EMPILHAR TODOS \n");
  printf("---------------------------------------\n");

  Pilha *p = pilha_criar();
  TipoElemento vetor[10];
  for (int i = 0; i < 10; i++)
  {
    vetor[i] = i;
  }

  pilha_empilharTodos(p, vetor, 10);

  TipoElemento saida;
  for (int i = 9; i >= 0; i--)
  {
    pilha_desempilhar(p, &saida);
    verifica(saida == i, "Empilhar todos");
  }

  pilha_destruir(&p);
}

int main()
{
  testeCriarDestruir();
  testeEmpilharDesempilharTamanho();
  testeTopoVazio();
  testeInverter();
  testeToString();
  testeClone();
  testeEmpilharTodos();

  return 0;
}