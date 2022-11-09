#include "fila.h"

/**************************************
 * DADOS
 **************************************/
typedef struct no
{
    int dado;
    struct no *prox;
} No;

struct fila
{
    No *inicio;
    No *fim;
    int qtde;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila *fila_criar()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtde = 0;
    return f;
};
void fila_destruir(Fila **enderecoFila)
{
    No *aux = (*enderecoFila)->inicio;
    while (aux != NULL)
    {
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(*enderecoFila);
    *enderecoFila = NULL;
};
bool fila_inserir(Fila *f, TipoElemento elemento)
{
    if (f == NULL)
        return false;
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;
    if (f->qtde == 0)
    {
        f->inicio = novo;
        f->fim = novo;
    }
    else
    {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->qtde++;
    return true;
};
bool fila_remover(Fila *f, TipoElemento *saida)
{
    if (f == NULL)
        return false;
    if (f->qtde == 0)
        return false;
    No *aux = f->inicio;
    *saida = aux->dado;
    f->inicio = aux->prox;
    free(aux);
    f->qtde--;
    return true;
}; // estratégia do scanf
bool fila_primeiro(Fila *f, TipoElemento *saida)
{
    if (f == NULL)
        return false;
    if (f->qtde == 0)
        return false;
    *saida = f->inicio->dado;
    return true;
}; // estratégia do scanf
bool fila_vazia(Fila *f)
{
    if (f == NULL)
        return false;
    return f->qtde == 0;
};
int fila_tamanho(Fila *f)
{
    if (f == NULL)
        return -1;
    return f->qtde;
};
void fila_imprimir(Fila *f)
{
    if (f == NULL)
        return;
    No *aux = f->inicio;
    while (aux != NULL)
    {
        printf(FORMATO, aux->dado);
        printf(" ");
        aux = aux->prox;
    }
};
Fila *fila_clone(Fila *f) {
    if (f == NULL)
        return NULL;
    Fila *nova = fila_criar();
    No *aux = f->inicio;
    while (aux != NULL) {
        fila_inserir(nova, aux->dado);
        aux = aux->prox;
    }
    return nova;
};
bool fila_toString(Fila *f, char *str) {
    if (f == NULL)
        return false;
    No *aux = f->inicio;
    char auxStr[100] = "";
    while (aux != NULL) {
        sprintf(auxStr, FORMATO, aux->dado);
        strcat(str, auxStr);
        strcat(str, " ");
        aux = aux->prox;
    }

    return true;
};
bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor) {
    if (f == NULL)
        return false;
    for (int i = 0; i < tamVetor; i++) {
        fila_inserir(f, vetor[i]);
    }
    return true;
};
