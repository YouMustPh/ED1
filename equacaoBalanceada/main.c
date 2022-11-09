#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"

bool verificarEquacaoBalanceadaEncadeada(char *equacao)
{
  Pilha *p = pilha_criar();
  if (p == NULL)
    return false;
  for (int i = 0; i < strlen(equacao); i++)
  {
    if (equacao[i] == '(' || equacao[i] == '[' || equacao[i] == '{')
    {
      pilha_empilhar(p, equacao[i]);
    }
    else if (equacao[i] == ')' || equacao[i] == ']' || equacao[i] == '}')
    {
      if (pilha_vazia(p))
      {
        pilha_destruir(&p);
        return false;
      }
      TipoElemento elemento;
      pilha_topo(p, &elemento);
      if ((elemento == '(' && equacao[i] == ')') || (elemento == '[' && equacao[i] == ']') || (elemento == '{' && equacao[i] == '}'))
      {
        pilha_desempilhar(p, &elemento);
      }
      else
      {
        pilha_destruir(&p);
        return false;
      }
    }
  }
  if (pilha_vazia(p))
  {
    pilha_destruir(&p);
    return true;
  }
  pilha_destruir(&p);
  return false;
};

bool verificarEquacaoBalanceadaContigua(char *equacao)
{
  Pilha *p = pilha_criar();
  if (p == NULL)
    return false;

  for (int i = 0; i < strlen(equacao); i++)
  {
    if (equacao[i] == '{' || equacao[i] == '(' || equacao[i] == '[')
    {
      pilha_empilhar(p, equacao[i]);
    }
    else if (equacao[i] == '}' || equacao[i] == ')' || equacao[i] == ']')
    {
      if (pilha_vazia(p))
      {
        pilha_destruir(&p);
        return false;
      }
      TipoElemento topo;
      pilha_topo(p, &topo);
      if ((equacao[i] == '}' && topo == '{') || (equacao[i] == ']' && topo == '[') || (equacao[i] == ')' && topo == '('))
      {
        pilha_desempilhar(p, &topo);
      }
      else
      {
        pilha_destruir(&p);
        return false;
      }
    }
  }
  if (pilha_vazia(p))
  {
    pilha_destruir(&p);
    return true;
  }
  pilha_destruir(&p);
  return false;
};

int main()
{
  char *equacao = "{[()]}";
  char *equacaoerrada = "{[(])}";

  printf("Equacao %s esta balanceada? %s\n", equacao, verificarEquacaoBalanceadaEncadeada(equacao) ? "sim" : "nao");
  printf("Equacao %s esta balanceada? %s\n", equacaoerrada, verificarEquacaoBalanceadaEncadeada(equacaoerrada) ? "sim" : "nao");

  printf("Equacao %s esta balanceada? %s\n", equacao, verificarEquacaoBalanceadaContigua(equacao) ? "sim" : "nao");
  printf("Equacao %s esta balanceada? %s\n", equacaoerrada, verificarEquacaoBalanceadaContigua(equacaoerrada) ? "sim" : "nao");

  return 0;
}