#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tad_vetor.h"

void verifica(int condicao, char* mensagem){
    if(condicao){
        printf("[OK] : %s\n",mensagem);
    }else{
        printf("Erro : %s\n",mensagem);
    }
}


void testeCriarDestruir(){
    printf("---------------------------------------\n");
    printf("TESTE CRIAR E DESTRUIR \n");
    printf("---------------------------------------\n");

    char resultado_string[200];
    Vetor* v1;
    v1 = vetor_criar();
    vetor_toString(v1, resultado_string);
    vetor_destruir(&v1);
    
    verifica(strcmp(resultado_string, "[]") == 0, "Criar vetor vazio");
    verifica(v1 == NULL, "Destruir vetor");
}

void testeAnexar(){
    printf("---------------------------------------\n");
    printf("TESTE ANEXAR \n");
    printf("---------------------------------------\n");

    char resultado_string[200];
    Vetor* v1;
    v1 = vetor_criar();

    vetor_anexar(v1, 10);
    vetor_toString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[10]") == 0, "Anexar 1/3");

    vetor_anexar(v1, 20);
    vetor_toString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[10, 20]") == 0, "Anexar 2/3");

    vetor_anexar(v1, 30);
    vetor_toString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[10, 20, 30]") == 0, "Anexar 3/3");


    vetor_destruir(&v1);
}

void testeInserir(){
    printf("---------------------------------------\n");
    printf("TESTE INSERIR \n");
    printf("---------------------------------------\n");

    char resultado_string[200];
    Vetor* v1;
    v1 = vetor_criar();

    vetor_anexar(v1, 10);
    vetor_anexar(v1, 20);
    vetor_anexar(v1, 30);

    vetor_inserir(v1, 5, 0);
    vetor_toString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[5, 10, 20, 30]") == 0, "Inserir primeira posicao");

    vetor_inserir(v1, 15, 2);
    vetor_toString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[5, 10, 15, 20, 30]") == 0, "Inserir no meio");
    

    vetor_inserir(v1, 40, 5);
    vetor_toString(v1, resultado_string);
    verifica(strcmp(resultado_string, "[5, 10, 15, 20, 30, 40]") == 0, "Inserir no fim");

    vetor_destruir(&v1);
}

void testeremoverPorPosicao(){
    printf("---------------------------------------\n");
    printf("TESTE REMOVER POR POSICAO \n");
    printf("---------------------------------------\n");

    Vetor* v1;
    v1 = vetor_criar();

    vetor_anexar(v1, 10);
    vetor_anexar(v1, 20);
    vetor_anexar(v1, 30);
    vetor_anexar(v1, 40);

    char resultado_string[200];
    int elementoRemovido;
    bool resultado;
    
    resultado = vetor_removerPorPosicao(v1, 0, &elementoRemovido);
    vetor_toString(v1, resultado_string);
    verifica(elementoRemovido == 10, "Remover primeira posicao 1/3");
    verifica(resultado == true, "Remover primeira posicao 2/3");
    verifica(strcmp(resultado_string, "[20, 30, 40]") == 0, "Remover primeira posicao 3/3");
    
    resultado = vetor_removerPorPosicao(v1, 1, &elementoRemovido);
    vetor_toString(v1, resultado_string);
    verifica(elementoRemovido == 30, "Remover Posicao Meio 1/3");
    verifica(resultado == true, "Remover Posicao Meio 2/3");
    verifica(strcmp(resultado_string, "[20, 40]") == 0, "Remover Posicao Meio 3/3");

    resultado = vetor_removerPorPosicao(v1, 1, &elementoRemovido);
    vetor_toString(v1, resultado_string);
    verifica(elementoRemovido == 40, "Remover ultima posicao 1/3");
    verifica(resultado == true, "Remover ultima posicao 2/3");
    verifica(strcmp(resultado_string, "[20]") == 0, "Remover ultima posicao 3/3");
    
    resultado = vetor_removerPorPosicao(v1, 0, &elementoRemovido);
    vetor_toString(v1, resultado_string);
    verifica(elementoRemovido == 20, "Remover unico elemento 1/3");
    verifica(resultado == true, "Remover unico elemento 2/3");
    verifica(strcmp(resultado_string, "[]") == 0, "Remover unico elemento 3/3");

    resultado = vetor_removerPorPosicao(v1, 0, &elementoRemovido);
    verifica(resultado == false, "Remover em um vetor vazio");

    vetor_destruir(&v1);
}


int main(){
    testeCriarDestruir();
    testeAnexar();
    testeInserir();
    testeremoverPorPosicao();
    

    return 0;
}