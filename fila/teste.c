#include "fila.h"

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

  Fila *f = fila_criar();
  verifica(f != NULL, "Criar fila");
  verifica(fila_vazia(f), "Fila vazia");
  fila_destruir(&f);
  verifica(f == NULL, "Destruir fila");
}

void testeInserirRemoverTamanho()
{
  printf("---------------------------------------\n");
  printf("TESTE INSERIR E REMOVER \n");
  printf("---------------------------------------\n");

  Fila *f = fila_criar();
  verifica(fila_inserir(f, 1), "Inserir 1");
  verifica(fila_inserir(f, 2), "Inserir 2");
  verifica(fila_inserir(f, 3), "Inserir 3");
  verifica(fila_inserir(f, 4), "Inserir 4");
  verifica(fila_inserir(f, 5), "Inserir 5");
  verifica(fila_inserir(f, 6), "Inserir 6");

  verifica(fila_tamanho(f) == 6, "Tamanho da fila");

  TipoElemento saida;
  verifica(fila_remover(f, &saida), "Remover 1");
  verifica(saida == 1, "Remover 1");
  verifica(fila_remover(f, &saida), "Remover 2");
  verifica(saida == 2, "Remover 2");
  verifica(fila_remover(f, &saida), "Remover 3");
  verifica(saida == 3, "Remover 3");
  verifica(fila_remover(f, &saida), "Remover 4");
  verifica(saida == 4, "Remover 4");
  verifica(fila_remover(f, &saida), "Remover 5");
  verifica(saida == 5, "Remover 5");
  verifica(fila_remover(f, &saida), "Remover 6");
  verifica(saida == 6, "Remover 6");

  fila_destruir(&f);
}

void testeInserirTodos()
{
  printf("---------------------------------------\n");
  printf("TESTE INSERIR TODOS \n");
  printf("---------------------------------------\n");

  Fila *f = fila_criar();
  int vetor[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  verifica(fila_inserirTodos(f, vetor, 12), "Inserir todos");
  verifica(fila_tamanho(f) == 12, "Tamanho da fila");

  fila_destruir(&f);
}

void testePrimeiro()
{
  printf("---------------------------------------\n");
  printf("TESTE PRIMEIRO \n");
  printf("---------------------------------------\n");

  Fila *f = fila_criar();
  verifica(fila_inserir(f, 1), "Inserir 1");
  verifica(fila_inserir(f, 2), "Inserir 2");
  verifica(fila_inserir(f, 3), "Inserir 3");
  verifica(fila_inserir(f, 4), "Inserir 4");
  verifica(fila_inserir(f, 5), "Inserir 5");
  verifica(fila_inserir(f, 6), "Inserir 6");

  TipoElemento saida;
  verifica(fila_primeiro(f, &saida), "Primeiro");
  verifica(saida == 1, "Primeiro");

  fila_destruir(&f);
}

void testeClone()
{
  printf("---------------------------------------\n");
  printf("TESTE CLONE \n");
  printf("---------------------------------------\n");

  Fila *f = fila_criar();
  verifica(fila_inserir(f, 1), "Inserir 1");
  verifica(fila_inserir(f, 2), "Inserir 2");
  verifica(fila_inserir(f, 3), "Inserir 3");
  verifica(fila_inserir(f, 4), "Inserir 4");
  verifica(fila_inserir(f, 5), "Inserir 5");
  verifica(fila_inserir(f, 6), "Inserir 6");

  Fila *clone = fila_clone(f);
  verifica(fila_tamanho(clone) == 6, "Tamanho da fila clone");

  fila_destruir(&f);
  fila_destruir(&clone);
}

void testeToStringImprimir()
{
  printf("---------------------------------------\n");
  printf("TESTE TO STRING E IMPRIMIR \n");
  printf("---------------------------------------\n");

  Fila *f = fila_criar();
  verifica(fila_inserir(f, 1), "Inserir 1");
  verifica(fila_inserir(f, 2), "Inserir 2");
  verifica(fila_inserir(f, 3), "Inserir 3");
  verifica(fila_inserir(f, 4), "Inserir 4");
  verifica(fila_inserir(f, 5), "Inserir 5");
  verifica(fila_inserir(f, 6), "Inserir 6");

  char saida[100] = "";
  verifica(fila_toString(f, saida), "To String");
  printf("Fila: %s\n", saida);

  fila_imprimir(f);

  fila_destruir(&f);
}

int main()
{
  testeCriarDestruirVazia();
  testeInserirRemoverTamanho();
  testeInserirTodos();
  testePrimeiro();
  testeClone();
  testeToStringImprimir();

  return 0;
}