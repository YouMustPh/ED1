#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"

#define TAM_INICIAL 5

/**************************************
 * DADOS
 **************************************/
struct pilha
{
  TipoElemento *vetor;
  int tamVetor;
  int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
// Desenvolva as funções
Pilha *pilha_criar()
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  if (p == NULL)
    return NULL;
  p->vetor = (TipoElemento *)calloc(TAM_INICIAL, sizeof(TipoElemento));
  if (p->vetor == NULL)
  {
    free(p);
    return NULL;
  }
  p->tamVetor = TAM_INICIAL;
  p->qtdeElementos = 0;
  return p;
};

void pilha_destruir(Pilha **endereco)
{
  if (endereco == NULL || *endereco == NULL)
    return;
  free((*endereco)->vetor);
  (*endereco)->vetor = NULL;
  free(*endereco);
  *endereco = NULL;
};

bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
  if (p == NULL)
    return false;
  if (p->qtdeElementos == p->tamVetor)
  {
    TipoElemento *novoVetor = (TipoElemento *)calloc(p->tamVetor + TAM_INICIAL, sizeof(TipoElemento));
    if (novoVetor == NULL)
    {
      return false;
    }
    for (int i = 0; i < p->tamVetor; i++)
    {
      novoVetor[i] = p->vetor[i];
    }
    free(p->vetor);
    p->vetor = novoVetor;
    p->tamVetor += TAM_INICIAL;
  }
  p->vetor[p->qtdeElementos] = elemento;
  p->qtdeElementos++;
  return true;
};
bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
  if (p == NULL || p->qtdeElementos == 0)
    return false;
  *saida = p->vetor[p->qtdeElementos - 1];
  p->qtdeElementos--;
  return true;
};
bool pilha_topo(Pilha *p, TipoElemento *saida)
{
  if (p == NULL || p->qtdeElementos == 0)
    return false;
  *saida = p->vetor[p->qtdeElementos - 1];
  return true;
};
bool pilha_vazia(Pilha *p)
{
  if (p == NULL)
    return true;
  return p->qtdeElementos == 0;
};
void pilha_imprimir(Pilha *p)
{
  if (p == NULL)
    return;
  printf("____\n");
  for (int i = p->qtdeElementos - 1; i >= 0; i--)
  {
    printf(FORMATO, p->vetor[i]);
    printf("\n");
  }
  printf("----\n");
};
int pilha_tamanho(Pilha *p)
{
  if (p == NULL)
    return 0;
  return p->qtdeElementos;
};
Pilha *pilha_clone(Pilha *p)
{
  if (p == NULL)
    return NULL;
  Pilha *clone = pilha_criar();
  if (clone == NULL)
    return NULL;
  for (int i = 0; i < p->qtdeElementos; i++)
  {
    pilha_empilhar(clone, p->vetor[i]);
  }
  return clone;
};
void pilha_inverter(Pilha *p)
{
  if (p == NULL)
    return;
  TipoElemento aux;
  for (int i = 0; i < p->qtdeElementos / 2; i++)
  {
    aux = p->vetor[i];
    p->vetor[i] = p->vetor[p->qtdeElementos - i - 1];
    p->vetor[p->qtdeElementos - i - 1] = aux;
  }
};
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{

  if (p == NULL || vetor == NULL || tamVetor <= 0)
    return false;
  for (int i = 0; i < tamVetor; i++)
  {
    pilha_empilhar(p, vetor[i]);
  }
  return true;
};
bool pilha_toString(Pilha *f, char *str)
{
  if (f == NULL || str == NULL)
    return false;
  char aux[100];
  strcpy(str, "----\n");
  for (int i = f->qtdeElementos - 1; i >= 0; i--)
  {
    sprintf(aux, FORMATO, f->vetor[i]);
    strcat(str, aux);
    strcat(str, "\n");
  }
  strcat(str, "----");
  return true;
};

