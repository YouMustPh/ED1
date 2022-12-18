#include "lista.h"

typedef struct no
{
  TipoElemento dado;
  struct no *ant;
  struct no *prox;
} No;

struct lista
{
  No *sentinela;
  int qtde;
};

Lista *lista_criar()
{
  Lista *l = (Lista *)malloc(sizeof(Lista));
  l->sentinela = (No *)malloc(sizeof(No));
  l->sentinela->ant = l->sentinela;
  l->sentinela->prox = l->sentinela;
  l->qtde = 0;
  return l;
};

void lista_destruir(Lista **endereco)
{
  Lista *l = *endereco;
  No *p = l->sentinela->prox;
  while (p != l->sentinela)
  {
    No *t = p->prox;
    free(p);
    p = t;
  }
  free(l->sentinela);
  free(l);
  *endereco = NULL;
};

bool lista_anexar(Lista *l, TipoElemento elemento)
{
  No *novo = (No *)malloc(sizeof(No));
  novo->dado = elemento;
  novo->prox = l->sentinela;
  novo->ant = l->sentinela->ant;
  l->sentinela->ant->prox = novo;
  l->sentinela->ant = novo;
  l->qtde++;
  return true;
};

bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
  if (posicao < 0 || posicao > l->qtde)
    return false;
  No *novo = (No *)malloc(sizeof(No));
  novo->dado = elemento;
  No *p = l->sentinela->prox;
  for (int i = 0; i < posicao; i++) {
    p = p->prox;
  }
  novo->prox = p;
  novo->ant = p->ant;
  p->ant->prox = novo;
  p->ant = novo;
  l->qtde++;
  return true;
};

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
  if (posicao < 0 || posicao > l->qtde)
    return false;
  No *p = l->sentinela->prox;
  for (int i = 0; i < posicao; i++) {
    p = p->prox;
  }
  *endereco = p->dado;
  p->ant->prox = p->prox;
  p->prox->ant = p->ant;
  free(p);
  l->qtde--;
  return true;
};

int lista_posicao(Lista *l, TipoElemento elemento)
{
  No *p = l->sentinela->prox;
  for (int i = 0; i < l->qtde; i++) {
    if (p->dado == elemento)
      return i;
    p = p->prox;
  }
  return -1;
};

int lista_removerElemento(Lista *l, TipoElemento elemento)
{
  int posicao = lista_posicao(l, elemento);
  if (posicao == -1)
    return -1;
  No *p = l->sentinela->prox;
  for (int i = 0; i < posicao; i++) {
    p = p->prox;
  }
  p->ant->prox = p->prox;
  p->prox->ant = p->ant;
  free(p);
  l->qtde--;
  return posicao;
};

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
  if (posicao < 0 || posicao > l->qtde)
    return false;
  No *p = l->sentinela->prox;
  for (int i = 0; i < posicao; i++) {
    p = p->prox;
  }
  p->dado = novoElemento;
  return true;
};

bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
  if (posicao < 0 || posicao > l->qtde)
    return false;
  No *p = l->sentinela->prox;
  for (int i = 0; i < posicao; i++) {
    p = p->prox;
  }
  *endereco = p->dado;
  return true;
};

int lista_tamanho(Lista *l)
{
  if (l == NULL)
    return -1;
  return l->qtde;
};

bool lista_vazia(Lista *l)
{
  if (l == NULL)
    return false;
  return l->qtde == 0;
};

bool lista_toString(Lista *l, char *str)
{
  if (l == NULL)
    return false;
  No *p = l->sentinela->prox;
  strcpy(str, "[");
  for (int i = 0; i < l->qtde; i++) {
    char aux[100];
    sprintf(aux, FORMATO, p->dado);
    strcat(str, aux);
    if (i < l->qtde - 1)
      strcat(str, ", ");
    p = p->prox;
  }
  strcat(str, "]");
  return true;
};