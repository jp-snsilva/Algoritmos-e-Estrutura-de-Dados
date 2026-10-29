#include "pilhaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Pilha *aluninhos = cria();
  struct aluno novo_aluno;
  printf("Digite a quantidade de alunos: ");
  int quant_alunos;
  scanf("%d", &quant_alunos);
  for (int i = 0; i < quant_alunos; i++) {
    struct aluno novo_aluno;

    printf("\n");
    printf("Digite o nome do aluno: ");
    scanf("%s", novo_aluno.nome);

    printf("Digite a idade do aluno: ");
    scanf("%d", &novo_aluno.idade);

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &novo_aluno.p1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &novo_aluno.p2);

    printf("Digite a notade projeto do aluno: ");
    scanf("%f", &novo_aluno.pj);

    if (inserir(aluninhos, novo_aluno) != 1) {
      printf("Nao foi possivel por na pilha...");
      break;
    }
  }

  if (acessar(aluninhos, &novo_aluno) == 1) {
    printf("Nome do aluno: %s\n", novo_aluno.nome);
    printf("Idade do aluno: %d\n", novo_aluno.idade);
    printf("Nota 1 do aluno: %.2f\n", novo_aluno.p1);
    printf("Nota 2 do aluno: %.2f\n", novo_aluno.p2);
    printf("Nota projeto do aluno: %.2f\n", novo_aluno.pj);
  }

  else
    printf("Nao deu certo\n");

  destruir(aluninhos);
}
