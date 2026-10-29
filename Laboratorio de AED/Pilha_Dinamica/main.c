#include "pilha_Dinamica.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // 1. Criar a pilha
  Pilha *pi = criar();
  if (pi == NULL) {
    printf("Erro ao alocar memoria para a pilha.\n");
    return 1;
  }

  // Verificar se esta vazia inicialmente
  if (vazia(pi)) {
    printf("A pilha esta vazia inicialmente.\n");
  } else {
    printf("A pilha nao esta vazia.\n");
  }

  // 2. Inserir elementos (Alunos)
  struct aluno a1 = {20, "Ana Silva", 8.5, 9.0, 8.0};
  struct aluno a2 = {22, "Bruno Souza", 7.0, 6.5, 7.5};
  struct aluno a3 = {21, "Carlos Lima", 9.0, 9.5, 10.0};

  printf("\n--- Inserindo alunos na pilha ---\n");
  inserir(pi, a1);
  printf("Inserido: %s (Idade: %d)\n", a1.nome, a1.idade);

  inserir(pi, a2);
  printf("Inserido: %s (Idade: %d)\n", a2.nome, a2.idade);

  inserir(pi, a3);
  printf("Inserido: %s (Idade: %d)\n", a3.nome, a3.idade);

  // 3. Verificar o tamanho da pilha
  printf("\nTamanho atual da pilha: %d\n", tamanho(pi));

  // 4. Acessar o elemento do topo
  struct aluno topo;
  if (acessar(pi, &topo)) {
    printf("\nElemento no topo:\n");
    printf("Nome: %s\n", topo.nome);
    printf("Idade: %d\n", topo.idade);
    printf("Notas: P1 = %.2f, P2 = %.2f, PJ = %.2f\n", topo.p1, topo.p2,
           topo.pj);
  } else {
    printf("\nNao foi possivel acessar o topo.\n");
  }

  // 5. Remover um elemento (desempilhar)
  printf("\n--- Removendo o elemento do topo ---\n");
  if (remover(pi)) {
    printf("Remocao realizada com sucesso!\n");
  } else {
    printf("Erro ao remover.\n");
  }

  // Verificar tamanho e novo topo apos a remocao
  printf("Novo tamanho da pilha: %d\n", tamanho(pi));
  if (acessar(pi, &topo)) {
    printf("Novo topo: %s\n", topo.nome);
  }

  // 6. Destruir a pilha
  destruir(pi);
  // Liberar o ponteiro principal da pilha criado pelo malloc em criar()
  free(pi);
  printf("\nPilha destruida com sucesso!\n");

  return 0;
}
