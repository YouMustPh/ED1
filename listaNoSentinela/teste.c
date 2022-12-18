#include "lista.h"

void verifica(int condicao, char *mensagem)
{
  if (condicao)
  {
    printf("[OK] : %s\n", mensagem);
  }
  else
  {
    printf("Erro : %s\n", mensagem);
  }
}

void testeCriarDestruirVazia()
{
  printf("---------------------------------------\n");
  printf("TESTE CRIAR, DESTRUIR E VAZIA \n");
  printf("---------------------------------------\n");

  Lista *l = lista_criar();
  verifica(l != NULL, "Criar lista");
  verifica(lista_vazia(l), "Lista vazia");
  lista_destruir(&l);
  verifica(l == NULL, "Destruir lista");
}

void testeAnexarRemoverTamanho()
{
  printf("---------------------------------------\n");
  printf("TESTE ANEXAR E REMOVER \n");
  printf("---------------------------------------\n");

  Lista *l = lista_criar();
  verifica(lista_anexar(l, 1), "Anexar 1");
  verifica(lista_anexar(l, 2), "Anexar 2");
  verifica(lista_anexar(l, 3), "Anexar 3");
  verifica(lista_anexar(l, 4), "Anexar 4");
  verifica(lista_anexar(l, 5), "Anexar 5");
  verifica(lista_anexar(l, 6), "Anexar 6");

  verifica(lista_tamanho(l) == 6, "Tamanho da lista");

  verifica(lista_removerElemento(l, 1) == 0, "Remover elemento 1");
  verifica(lista_removerElemento(l, 2) == 0, "Remover elemento 2");
  verifica(lista_removerElemento(l, 3) == 0, "Remover elemento 3");
  verifica(lista_removerElemento(l, 4) == 0, "Remover elemento 4");
  verifica(lista_removerElemento(l, 5) == 0, "Remover elemento 5");
  verifica(lista_removerElemento(l, 6) == 0, "Remover elemento 6");

  verifica(lista_tamanho(l) == 0, "Tamanho da lista");

  lista_destruir(&l);
}

void testeInserirRemoverPosicao()
{
  printf("---------------------------------------\n");
  printf("TESTE INSERIR E REMOVER POSICAO \n");
  printf("---------------------------------------\n");

  Lista *l = lista_criar();
  lista_anexar(l, 1);
  lista_anexar(l, 2);
  lista_anexar(l, 3);
  lista_anexar(l, 4);
  lista_anexar(l, 5);
  lista_anexar(l, 6);

  verifica(lista_inserir(l, 7, 0), "Inserir 7 na posicao 0");
  verifica(lista_inserir(l, 8, 2), "Inserir 8 na posicao 2");
  verifica(lista_inserir(l, 9, 6), "Inserir 9 na posicao 6");
  verifica(lista_inserir(l, 10, 8), "Inserir 10 na posicao 8");

  TipoElemento saida;
  verifica(lista_removerPosicao(l, 0, &saida), "Remover 7");
  verifica(saida == 7, "Remover 7");
  verifica(lista_removerPosicao(l, 1, &saida), "Remover 8");
  verifica(saida == 8, "Remover 8");
  verifica(lista_removerPosicao(l, 4, &saida), "Remover 9");
  verifica(saida == 9, "Remover 9");
  verifica(lista_removerPosicao(l, 5, &saida), "Remover 10");
  verifica(saida == 10, "Remover 10");

  lista_destruir(&l);
}

void testeSubstituirPosicaoBuscar()
{
  printf("---------------------------------------\n");
  printf("TESTE SUBSTITUIR POSICAO E BUSCAR \n");
  printf("---------------------------------------\n");

  Lista *l = lista_criar();
  lista_anexar(l, 1);
  lista_anexar(l, 2);
  lista_anexar(l, 3);
  lista_anexar(l, 4);
  lista_anexar(l, 5);
  lista_anexar(l, 6);
  lista_anexar(l, 7);
  lista_anexar(l, 8);

  verifica(lista_substituir(l, 0, 7), "Substituir 7 na posicao 0");
  verifica(lista_substituir(l, 2, 8), "Substituir 8 na posicao 2");
  verifica(lista_substituir(l, 5, 9), "Substituir 9 na posicao 5");
  verifica(lista_substituir(l, 7, 10), "Substituir 10 na posicao 8");

  int posicao = 0;
  posicao = lista_posicao(l, 7);
  verifica(posicao == 0, "Posicao 7");
  posicao = lista_posicao(l, 8);
  verifica(posicao == 2, "Posicao 8");
  posicao = lista_posicao(l, 9);
  verifica(posicao == 5, "Posicao 9");
  posicao = lista_posicao(l, 10);
  verifica(posicao == 7, "Posicao 10");

  TipoElemento saida;
  verifica(lista_buscar(l, 0, &saida), "Buscar 7");
  verifica(saida == 7, "Buscar 7");
  verifica(lista_buscar(l, 2, &saida), "Buscar 8");
  verifica(saida == 8, "Buscar 8");
  verifica(lista_buscar(l, 5, &saida), "Buscar 9");
  verifica(saida == 9, "Buscar 9");
  verifica(lista_buscar(l, 7, &saida), "Buscar 10");
  verifica(saida == 10, "Buscar 10");

  lista_destruir(&l);
}

void testeToString()
{
  printf("---------------------------------------\n");
  printf("TESTE TO STRING \n");
  printf("---------------------------------------\n");

  Lista *l = lista_criar();
  lista_anexar(l, 1);
  lista_anexar(l, 2);
  lista_anexar(l, 3);
  lista_anexar(l, 4);
  lista_anexar(l, 5);
  lista_anexar(l, 6);

  char saida[100] = "";
  verifica(lista_toString(l, saida), "To String");
  printf("Lista: %s \n", saida);
    
  lista_destruir(&l);
}

int main()
{
  testeCriarDestruirVazia();
  testeAnexarRemoverTamanho();
  testeInserirRemoverPosicao();
  testeSubstituirPosicaoBuscar();
  testeToString();

  return 0;
}