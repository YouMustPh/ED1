#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no
{
  int dado;
  struct no *prox;
} No;

No* novoNo (int dado)
{
  No *novo = malloc(sizeof(No));
  novo->dado = dado;
  novo->prox = NULL;

 novo;
}

No* novoNo2 (int dado, No* no)
{
  No *novo = malloc(sizeof(No));
  novo->dado = dado;
  novo->prox = no;

  novo;
}

int main () {
  No* l;
  l = novoNo(10);

  No* aux;
  aux = novoNo(20);

  //encadeamento do No aux
  l->prox = aux;

  aux = novoNo(30);

  //encadeamento do No aux
  l->prox->prox = aux;

  //zerar a variável aux
  aux = NULL;


  aux = l;
  while(aux != NULL)
  {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }

  return 0;
}