#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "pilha.h"

/**************************************
 * DADOS
 **************************************/
typedef struct no
{
	TipoElemento dado;
	struct no *prox;
} No;

struct pilha
{
	No *topo;
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
	p->topo = NULL;
	p->qtdeElementos = 0;
	return p;
};
void pilha_destruir(Pilha **endereco)
{
	if (endereco == NULL || *endereco == NULL)
		return;
	No *aux = (*endereco)->topo;
	while (aux != NULL)
	{
		No *aux2 = aux->prox;
		free(aux);
		aux = aux2;
	}
	free(*endereco);
	*endereco = NULL;
};
bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
	if (p == NULL)
		return false;
	No *novo = (No *)malloc(sizeof(No));
	if (novo == NULL)
		return false;
	novo->dado = elemento;
	novo->prox = p->topo;
	p->topo = novo;
	p->qtdeElementos++;
	return true;
};
bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
	if (p == NULL || p->topo == NULL)
		return false;
	No *aux = p->topo;
	*saida = aux->dado;
	p->topo = aux->prox;
	free(aux);
	p->qtdeElementos--;
	return true;
};
bool pilha_topo(Pilha *p, TipoElemento *saida)
{
	if (p == NULL || p->topo == NULL)
		return false;
	*saida = p->topo->dado;
	return true;
};
bool pilha_vazia(Pilha *p)
{
	if (p == NULL)
		return false;
	return p->topo == NULL;
};
void pilha_imprimir(Pilha *p)
{
	if (p == NULL)
		return;
	No *aux = p->topo;
	printf("---- \n");
	while (aux != NULL)
	{
		printf("%d \n", aux->dado);
		aux = aux->prox;
	}
	printf("---- \n");
	printf("\n");
};
int pilha_tamanho(Pilha *p)
{
	if (p == NULL)
		return -1;
	return p->qtdeElementos;
};
Pilha *pilha_clone(Pilha *p)
{
	if (p == NULL)
		return NULL;
	Pilha *clone = pilha_criar();
	if (clone == NULL)
		return NULL;
	No *aux = p->topo;
	Pilha *cloneAux = pilha_criar();
	while (aux != NULL)
	{
		pilha_empilhar(cloneAux, aux->dado);
		aux = aux->prox;
	}
	aux = cloneAux->topo;
	while (aux != NULL)
	{
		pilha_empilhar(clone, aux->dado);
		aux = aux->prox;
	}
	pilha_destruir(&cloneAux);

	return clone;
};
void pilha_inverter(Pilha *p)
{
	if (p == NULL)
		return;
	Pilha *aux = pilha_criar();
	if (aux == NULL)
		return;
	while (!pilha_vazia(p))
	{
		TipoElemento elemento;
		pilha_desempilhar(p, &elemento);
		pilha_empilhar(aux, elemento);
	}
	p->topo = aux->topo;
	p->qtdeElementos = aux->qtdeElementos;
	free(aux);
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
	No *aux = f->topo;
	char auxStr[100];
	strcpy(str, "----\n");
	while (aux != NULL)
	{
		sprintf(auxStr, "%d\n", aux->dado);
		strcat(str, auxStr);
		aux = aux->prox;
	}
	strcat(str, "----");
	return true;
};