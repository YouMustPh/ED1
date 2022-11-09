#include "tad_vetor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ESPECIFICACAO DOS DADOS
struct vetor
{
    int *array;
    int tam;
    int qtd;
};

// FUNCOES AUXILIARES

bool verifica_aumenta(Vetor *v)
{
    if (v->qtd < v->tam)
        return true;

    int novoTamanho = v->tam * 2;

    int *temp = (int *)calloc(novoTamanho, sizeof(int));

    if (temp == NULL)
        return false;

    memcpy(temp, v->array, v->qtd * sizeof(int));

    free(v->array);
    v->array = temp;
    v->tam = novoTamanho;

    return true;
}

// IMPLEMENTAÇÃO
Vetor *vetor_criar()
{
    Vetor *vet = malloc(sizeof(Vetor));
    vet->array = malloc(MAX * sizeof(int));
    vet->tam = MAX;
    vet->qtd = 0;
    return vet;
};
void vetor_destruir(Vetor **endereco)
{
    free((*endereco)->array);
    free(*endereco);
    *endereco = NULL;
};
bool vetor_anexar(Vetor *v, int elemento)
{
    if (!verifica_aumenta(v))
        return false;

    if (v->qtd == v->tam)
    {
        return false;
    }
    v->array[v->qtd] = elemento;
    v->qtd++;
    return true;
};
void vetor_imprimir(Vetor *v)
{
    printf("[");
    for (int i = 0; i < v->qtd; i++)
    {
        printf("%d", v->array[i]);
        if (i < v->qtd - 1)
        {
            printf(", ");
        }
    }
    printf("]");
};
void vetor_toString(Vetor *v, char *str)
{
    strcpy(str, "[");
    for (int i = 0; i < v->qtd; i++)
    {
        char aux[v->qtd];
        sprintf(aux, "%d", v->array[i]);
        strcat(str, aux);
        if (i < v->qtd - 1)
        {
            strcat(str, ", ");
        }
    }
    strcat(str, "]");
};
bool vetor_inserir(Vetor *v, int elemento, int pos)
{
    if (v == NULL || pos < 0 || pos > v->qtd || !verifica_aumenta(v))
    {
        return false;
    }

    for (int i = v->qtd; i > pos; i--)
    {
        v->array[i] = v->array[i - 1];
    }
    v->array[pos] = elemento;
    v->qtd++;

    return true;
};
bool vetor_removerPorPosicao(Vetor *v, int pos, int *endereco)
{
    if (pos < 0 || pos >= v->qtd || v == NULL)
    {
        return false;
    }

    *endereco = v->array[pos];
    for (int i = pos; i < v->qtd - 1; i++)
    {
        v->array[i] = v->array[i + 1];
    }
    v->qtd--;

    return true;
};

/***********************************************
 * PARTE 2
 ************************************************/
int vetor_posicao(Vetor *v, int elemento)
{
    for (int i = 0; i < v->qtd; i++)
    {
        if (v->array[i] == elemento)
        {
            return i;
        }
    }
    return -1;
};

int vetor_removerElemento(Vetor *v, int elemento)
{
    int pos = vetor_posicao(v, elemento);

    vetor_removerPorPosicao(v, pos, &elemento);

    return pos;
};

bool vetor_elemento(Vetor *v, int pos, int *saida)
{
    if (pos < 0 || pos >= v->qtd || v == NULL)
    {
        return false;
    }
    *saida = v->array[pos];
    return true;
};

int vetor_tamanho(Vetor *v)
{
    return v->qtd;
};

Vetor *vetor_criarAleatorio(int qtd)
{
    Vetor *vr = vetor_criar();

    for (int i = 0; i < qtd; i++)
    {
        vetor_anexar(vr, rand());
    }

    return vr;
};

Vetor *vetor_importar(char *nomeArquivo)
{
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL)
    {
        return NULL;
    }

    Vetor *vet = vetor_criar();

    fscanf(arq, "%d", &vet->qtd);

    for (int i = 0; i < vet->qtd; i++)
    {
        fscanf(arq, "%d", &vet->array[i]);
    }

    fclose(arq);

    return vet;
};
bool vet_substituir(Vetor *v, int pos, int novoElemento)
{
    if (pos < 0 || pos >= v->qtd || v == NULL)
    {
        return false;
    }
    v->array[pos] = novoElemento;
    return true;
};

/***********************************************
 * PARTE 3
 ************************************************/

void saveBinary(Vetor *v, char *nomeArquivo)
{
    FILE *arq = fopen(nomeArquivo, "wb");
    if (arq == NULL)
    {
        return;
    }

    fwrite(&v->tam, sizeof(int), 1, arq);
    fwrite(&v->qtd, sizeof(int), 1, arq);
    fwrite(v->array, sizeof(int), v->qtd, arq);

    fclose(arq);
};

Vetor *loadBinary(char *nomeArquivo)
{
    FILE *arq = fopen(nomeArquivo, "rb");
    if (arq == NULL)
    {
        return NULL;
    }

    Vetor *vet = vetor_criar();

    fread(&vet->tam, sizeof(int), 1, arq);
    fread(&vet->qtd, sizeof(int), 1, arq);
    verifica_aumenta(vet);
    
    fread(vet->array, sizeof(int), vet->qtd, arq);

    fclose(arq);

    return vet;
};