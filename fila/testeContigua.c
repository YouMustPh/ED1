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

void testeCriarDestruir()
{
  printf("---------------------------------------\n");
  printf("TESTE CRIAR E DESTRUIR \n");
  printf("---------------------------------------\n");

  Fila *f = fila_criar();
  verifica(f != NULL, "Criar fila");
  fila_destruir(&f);
  verifica(f == NULL, "Destruir fila");
}

void testeInserirRemover()
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

int main () {
  testeCriarDestruir();
  testeInserirRemover();
  return 0;
}