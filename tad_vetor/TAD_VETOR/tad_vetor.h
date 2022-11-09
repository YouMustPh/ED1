#ifndef TAD_VETOR
#define TAD_VETOR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// DADOS

typedef struct vetor Vetor;

// PROTÓTIPOS

Vetor *vetor_criar();
void vetor_destruir(Vetor **endereco);
bool vetor_anexar(Vetor *v, int elemento);
void vetor_imprimir(Vetor *v);
void vetor_toString(Vetor *v, char *str);
bool vetor_inserir(Vetor *v, int elemento, int pos);
bool vetor_removerPorPosicao(Vetor *v, int pos, int *endereco);
int vetor_removerElemento(Vetor *v, int elemento);
bool vetor_elemento(Vetor *v, int pos, int *saida);
int vetor_posicao(Vetor *v, int elemento);
int vetor_tamanho(Vetor *v);
Vetor *vetor_criarAleatorio(int qtd);
Vetor *vetor_importar(char *nomeArquivo);
bool vet_substituir(Vetor *v, int pos, int novoElemento);
void saveBinary(Vetor *v, char *nomeArquivo);
Vetor *loadBinary(char *nomeArquivo);

#endif
