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

void testeRemoverElemento(){
    printf("---------------------------------------\n");
    printf("TESTE REMOVER ELEMENTO \n");
    printf("---------------------------------------\n");

    Vetor* v1 = vetor_criar();

    vetor_anexar(v1, 10);
    vetor_anexar(v1, 20);
    vetor_anexar(v1, 30);
    vetor_anexar(v1, 40);

    char resultado_string[200];
    int posicao;
    
    posicao = vetor_removerElemento(v1, 200);
    vetor_toString(v1, resultado_string);
    verifica(posicao == -1, "Remover elemento que nao existe 1/2");    
    verifica(strcmp(resultado_string, "[10, 20, 30, 40]") == 0, "Remover elemento que nao existe 2/2");


    posicao = vetor_removerElemento(v1, 10);
    vetor_toString(v1, resultado_string);
    verifica(posicao == 0, "Remover elemento da primeira posicao 1/2");    
    verifica(strcmp(resultado_string, "[20, 30, 40]") == 0, "Remover elemento da primeira posicao 2/2");

    posicao = vetor_removerElemento(v1, 30);
    vetor_toString(v1, resultado_string);
    verifica(posicao == 1, "Remover elemento do meio 1/2");    
    verifica(strcmp(resultado_string, "[20, 40]") == 0, "Remover elemento do meio 2/2");

    posicao = vetor_removerElemento(v1, 40);
    vetor_toString(v1, resultado_string);
    verifica(posicao == 1, "Remover elemento do fim 1/2");    
    verifica(strcmp(resultado_string, "[20]") == 0, "Remover elemento do fim 2/2");

    posicao = vetor_removerElemento(v1, 20);
    vetor_toString(v1, resultado_string);
    verifica(posicao == 0, "Remover unico elemento do vetor 1/2");    
    verifica(strcmp(resultado_string, "[]") == 0, "Remover unico elemento do vetor 2/2");

    posicao = vetor_removerElemento(v1, 10);    
    verifica(posicao == -1, "Remover elemento no vetor vazio 1/1");    

}

void testePosicao(){
    printf("---------------------------------------\n");
    printf("TESTE VETOR_POSICAO \n");
    printf("---------------------------------------\n");

    Vetor* v1 = vetor_criar();

    vetor_anexar(v1, 10);
    vetor_anexar(v1, 20);
    vetor_anexar(v1, 30);
    

    char resultado_string[200];
    int posicao;

    posicao = vetor_posicao(v1, 10);
    verifica(posicao == 0, "vetor_posicao 1/4");
    posicao = vetor_posicao(v1, 20);
    verifica(posicao == 1, "vetor_posicao 2/4");
    posicao = vetor_posicao(v1, 30);
    verifica(posicao == 2, "vetor_posicao 3/4");
    posicao = vetor_posicao(v1, -50);
    verifica(posicao == -1, "vetor_posicao 4/4");

    verifica(vetor_tamanho(v1) == 3, "Tamanho do vetor");

    vetor_destruir(&v1);
}

void testeElemento(){
    printf("---------------------------------------\n");
    printf("TESTE VETOR_POSICAO \n");
    printf("---------------------------------------\n");

    Vetor* v1 = vetor_criar();

    vetor_anexar(v1, 10);
    vetor_anexar(v1, 20);
    vetor_anexar(v1, 30);
    

    char resultado_string[200];
    int elemento;
    bool resultado;

    resultado = vetor_elemento(v1, 0, &elemento);
    verifica(resultado == true && elemento == 10, "vetor_elemento 1/4");

    resultado = vetor_elemento(v1, 1, &elemento);
    verifica(resultado == true && elemento == 20, "vetor_elemento 2/4");

    resultado = vetor_elemento(v1, 2, &elemento);
    verifica(resultado == true && elemento == 30, "vetor_elemento 3/4");

    resultado = vetor_elemento(v1, 5, &elemento);
    verifica(resultado == false, "vetor_elemento 4/4");

    vetor_destruir(&v1);
}

void testeCriarAleatorio(){
    printf("---------------------------------------\n");
    printf("TESTE VETOR ALEATORIO \n");
    printf("---------------------------------------\n");

    char resultado_string[500];
    

    Vetor* v1 = vetor_criarAleatorio(5);
    vetor_toString(v1, resultado_string);
    printf("%s\n", resultado_string);
    verifica(vetor_tamanho(v1) == 5, "Vetor aleatorio 1/2");


    Vetor* v2 = vetor_criarAleatorio(10);
    vetor_toString(v2, resultado_string);
    printf("%s\n", resultado_string);
    verifica(vetor_tamanho(v2) == 10, "Vetor aleatorio 2/2");

    vetor_destruir(&v1);
    vetor_destruir(&v2);

}

void testeSalvarCarregar(){
    printf("---------------------------------------\n");
    printf("TESTE SALVAR E CARREGAR \n");
    printf("---------------------------------------\n");

    Vetor* v1 = vetor_criarAleatorio(5);
    char resultado_string2[500];
    vetor_toString(v1, resultado_string2);
    printf("%s\n", resultado_string2);
    verifica(vetor_tamanho(v1) == 5, "Vetor criado");
    saveBinary(v1, "teste.txt");
    verifica(vetor_tamanho(v1) == 5, "Vetor Salvo");
    vetor_destruir(&v1);

    v1 = loadBinary("teste.txt");
    char resultado_string[500];
    vetor_toString(v1, resultado_string);
    printf("%s\n", resultado_string);
    verifica(vetor_tamanho(v1) == 5, "Vetor carregado 1/1");

    vetor_destruir(&v1);
}

int main(){

    testeRemoverElemento();
    testeElemento();
    testePosicao();
    testeCriarAleatorio();
    testeSalvarCarregar();

    return 0;
}