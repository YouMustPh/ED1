#include "fila.h"

#define TAM_INICIAL 5
/**************************************
 * DADOS
 **************************************/
struct fila
{
	TipoElemento *vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila *fila_criar()
{
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->vetor = (TipoElemento *)calloc(TAM_INICIAL, sizeof(TipoElemento));
	f->fim = 0;
	f->inicio = 0;
	f->qtdeElementos = 0;
	f->tamVetor = TAM_INICIAL;
	return f;
};
void fila_destruir(Fila **enderecoFila)
{
	free((*enderecoFila)->vetor);
	free(*enderecoFila);
	*enderecoFila = NULL;
};
bool fila_inserir(Fila *f, TipoElemento elemento)
{
	if (f == NULL)return false;
	if (f->qtdeElementos == f->tamVetor)
	{
		TipoElemento *novoVetor = (TipoElemento *)calloc(f->tamVetor * 2, sizeof(TipoElemento));
		for (int i = 0; i < f->tamVetor; i++)
		{
			novoVetor[i] = f->vetor[(f->inicio + i) % f->tamVetor];
		}
		free(f->vetor);
		f->vetor = novoVetor;
		f->inicio = 0;
		f->fim = f->tamVetor;
		f->tamVetor *= 2;
	}
	f->vetor[f->fim] = elemento;
	f->fim = (f->fim + 1) % f->tamVetor;
	f->qtdeElementos++;
	return true;
};
bool fila_remover(Fila *f, TipoElemento *saida){
	if (f == NULL)return false;
	if (f->qtdeElementos == 0)return false;
	*saida = f->vetor[f->inicio];
	f->inicio = (f->inicio + 1) % f->tamVetor;
	f->qtdeElementos--;
	return true;
}; // estratégia do scanf
void fila_imprimir(Fila *f) {
	if (f == NULL)return;
	for (int i = 0; i < f->qtdeElementos; i++)
	{
		printf(FORMATO, f->vetor[(f->inicio + i) % f->tamVetor]);
		printf(" ");
	}
	printf("\n");
};
