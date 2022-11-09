#include "lista.h"

typedef struct no
{
  TipoElemento dado;
  struct no *ant;
  struct no *prox;
} No;

struct lista
{
  No *inicio;
  No *fim;
  int qtde;
};

Lista *lista_criar()
{
  Lista *l = (Lista *)malloc(sizeof(Lista));
  l->inicio = NULL;
  l->fim = NULL;
  l->qtde = 0;
  return l;
};
void lista_destruir(Lista **endereco)
{
  Lista *l = *endereco;
  No *aux = l->inicio;
  while (aux != NULL)
  {
    No *t = aux->prox;
    free(aux);
    aux = t;
  }
  free(l);
  *endereco = NULL;
};

bool lista_anexar(Lista *l, TipoElemento elemento)
{
  No *no = (No *)malloc(sizeof(No));
  no->dado = elemento;
  no->prox = NULL;
  no->ant = l->fim;
  if (l->fim != NULL)
  {
    l->fim->prox = no;
  }
  l->fim = no;
  if (l->inicio == NULL)
  {
    l->inicio = no;
  }
  l->qtde++;
  return true;
};
bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
  if (posicao < 0 || posicao > l->qtde)
    return false;
  if (posicao == 0)
  {
    No *no = (No *)malloc(sizeof(No));
    no->dado = elemento;
    no->prox = l->inicio;
    no->ant = NULL;
    if (l->inicio != NULL)
    {
      l->inicio->ant = no;
    }
    l->inicio = no;
    if (l->fim == NULL)
    {
      l->fim = no;
    }
    l->qtde++;
    return true;
  }
  if (posicao == l->qtde)
    return lista_anexar(l, elemento);
  No *aux = l->inicio;
  for (int i = 0; i < posicao; i++)
    aux = aux->prox;
  No *no = (No *)malloc(sizeof(No));
  no->dado = elemento;
  no->prox = aux;
  no->ant = aux->ant;
  aux->ant->prox = no;
  aux->ant = no;
  l->qtde++;
  return true;
};

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
  if (posicao < 0 || posicao > l->qtde)
    return false;
  if (posicao == 0)
  {
    No *aux = l->inicio;
    l->inicio = aux->prox;
    if (l->inicio != NULL)
    {
      l->inicio->ant = NULL;
    }
    *endereco = aux->dado;
    free(aux);
    l->qtde--;
    return true;
  }
  if (posicao == l->qtde)
  {
    No *aux = l->fim;
    l->fim = aux->ant;
    if (l->fim != NULL)
    {
      l->fim->prox = NULL;
    }
    *endereco = aux->dado;
    free(aux);
    l->qtde--;
    return true;
  }
  No *aux = l->inicio;
  for (int i = 0; i < posicao; i++)
    aux = aux->prox;
  aux->ant->prox = aux->prox;
  aux->prox->ant = aux->ant;
  *endereco = aux->dado;
  free(aux);
  l->qtde--;
  return true;
};
int lista_posicao(Lista *l, TipoElemento elemento)
{
  No *aux = l->inicio;
  for (int i = 0; i < l->qtde; i++)
  {
    if (aux->dado == elemento)
      return i;
    aux = aux->prox;
  }
  return -1;
};

int lista_removerElemento(Lista *l, TipoElemento elemento)
{
  int pos = lista_posicao(l, elemento);
  if (pos == -1)
    return -1;
  lista_removerPosicao(l, pos, &elemento);
  return pos;
};

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
  if (posicao < 0 || posicao > l->qtde)
    return false;
  No *aux = l->inicio;
  for (int i = 0; i < posicao; i++)
    aux = aux->prox;
  aux->dado = novoElemento;
  return true;
};
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
  if (posicao < 0 || posicao > l->qtde)
    return false;
  No *aux = l->inicio;
  for (int i = 0; i < posicao; i++)
    aux = aux->prox;
  *endereco = aux->dado;
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
  No *aux = l->inicio;
  char auxStr[100];
  strcpy(str, "[");
  for (int i = 0; i < l->qtde; i++)
  {
    sprintf(auxStr, FORMATO, aux->dado);
    strcat(str, auxStr);
    if (i < l->qtde - 1)
      strcat(str, ", ");
    aux = aux->prox;
  }
  strcat(str, "]");
  return true;
};