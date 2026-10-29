#include "fila_Dinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // 1. Criar a fila
  Fila *fi = criar();
  if (fi == NULL) {
    printf("Erro ao alocar memoria para a fila.\n");
    return 1;
  }

  // Verificar se esta vazia inicialmente
  if (vazia(fi)) {
    printf("A fila esta vazia inicialmente.\n");
  } else {
    printf("A fila nao esta vazia.\n");
  }

  // 2. Definir alguns alunos para teste
  struct aluno a1 = {20, "Ana Silva", 8.5, 9.0, 8.0};
  struct aluno a2 = {22, "Bruno Souza", 7.0, 6.5, 7.5};
  struct aluno a3 = {21, "Carlos Lima", 9.0, 9.5, 10.0};

  // 3. Inserir elementos na fila
  printf("\n--- A inserir alunos na fila ---\n");
  inserir(fi, a1);
  printf("Inserido: %s\n", a1.nome);

  inserir(fi, a2);
  printf("Inserido: %s\n", a2.nome);

  inserir(fi, a3);
  printf("Inserido: %s\n", a3.nome);

  // 4. Verificar o tamanho da fila
  printf("\nTamanho atual da fila: %d\n", tamanho(fi));

  // 5. Aceder ao elemento do início da fila
  struct aluno primeiro;
  if (acessar(fi, &primeiro)) {
    printf("\nElemento no inicio da fila:\n");
    printf("Nome: %s\n", primeiro.nome);
    printf("Idade: %d\n", primeiro.idade);
    printf("Notas: P1 = %.2f, P2 = %.2f, PJ = %.2f\n", primeiro.p1, primeiro.p2,
           primeiro.pj);
  } else {
    printf("\nNao foi possivel aceder ao inicio.\n");
  }

  // 6. Remover um elemento da fila
  printf("\n--- A remover o elemento do inicio ---\n");
  if (remover(fi)) {
    printf("Remocao realizada com sucesso!\n");
  } else {
    printf("Erro ao remover.\n");
  }

  // Verificar o tamanho apos a remocao
  printf("Novo tamanho da fila: %d\n", tamanho(fi));

  // 7. Destruir a fila e libertar a memoria
  destruir(fi);
  free(fi); // Liberta o ponteiro principal alocado na função criar()
  printf("\nFila destruida com sucesso!\n");

  return 0;
}
