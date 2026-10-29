
#include "listaSimplesmenteEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar para limpar o buffer do teclado
void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Função auxiliar para ler os dados de um aluno do teclado
struct aluno lerDadosAluno() {
  struct aluno novoAluno;

  printf("\n--- Digite os dados do Aluno ---\n");
  printf("Nome: ");
  fgets(novoAluno.nome, 50, stdin);
  novoAluno.nome[strcspn(novoAluno.nome, "\n")] =
      '\0'; // Remove o '\n' do final

  printf("Idade: ");
  scanf("%d", &novoAluno.idade);

  printf("Nota P1: ");
  scanf("%f", &novoAluno.p1);

  printf("Nota P2: ");
  scanf("%f", &novoAluno.p2);

  printf("Nota PJ: ");
  scanf("%f", &novoAluno.pj);
  limparBuffer();

  return novoAluno;
}

// Função auxiliar para mostrar toda a lista na tela usando a sua função
// acessarIndice
void exibirLista(Lista *ldse) {
  printf("\n================ LISTA DE ALUNOS (Tamanho: %d) ================\n",
         tamanho(ldse));
  if (vazia(ldse)) {
    printf("A lista esta vazia.\n");
    printf("===============================================================\n");
    return;
  }

  struct aluno alu;
  int i = 0;
  while (acessarIndice(ldse, i, &alu)) {
    printf("[%d] Nome: %-15s | Idade: %d | Notas: P1=%.1f, P2=%.1f, PJ=%.1f\n",
           i, alu.nome, alu.idade, alu.p1, alu.p2, alu.pj);
    i++;
  }
  printf("===============================================================\n");
}

int main() {
  Lista *minhaLista = criar();
  if (minhaLista == NULL) {
    printf("Erro catastrofico: Nao foi possivel alocar a lista!\n");
    return 1;
  }

  int opcao;
  struct aluno alunoTmp;
  int idadeBusca, indiceBusca;

  do {
    printf("\n========= MENU DE TESTES =========\n");
    printf("1. Inserir no Inicio\n");
    printf("2. Inserir no Final\n");
    printf("3. Inserir Ordenado (por idade)\n");
    printf("4. Remover do Inicio\n");
    printf("5. Remover do Fim\n");
    printf("6. Remover por Idade (Valor)\n");
    printf("7. Acessar por Indice\n");
    printf("8. Acessar por Idade (Valor)\n");
    printf("9. Exibir Lista Completa\n");
    printf("0. Sair e Destruir Lista\n");
    printf("Escolha uma opcao: ");

    if (scanf("%d", &opcao) != 1) {
      printf("Opcao invalida!\n");
      limparBuffer();
      continue;
    }
    limparBuffer();

    switch (opcao) {
    case 1:
      alunoTmp = lerDadosAluno();
      if (inserirInicio(minhaLista, alunoTmp))
        printf("Sucesso: Aluno inserido no inicio!\n");
      else
        printf("Falha ao inserir.\n");
      break;

    case 2:
      alunoTmp = lerDadosAluno();
      if (inserirFinal(minhaLista, alunoTmp))
        printf("Sucesso: Aluno inserido no final!\n");
      else
        printf("Falha ao inserir.\n");
      break;

    case 3:
      alunoTmp = lerDadosAluno();
      if (inserirOrdenado(minhaLista, alunoTmp))
        printf("Sucesso: Aluno inserido na posicao correta por idade!\n");
      else
        printf("Falha ao inserir de forma ordenada.\n");
      break;

    case 4:
      if (removerInicio(minhaLista))
        printf("Sucesso: Primeiro aluno removido!\n");
      else
        printf("Falha: Lista vazia ou nao alocada.\n");
      break;

    case 5:
      if (removerFim(minhaLista))
        printf("Sucesso: Ultimo aluno removido!\n");
      else
        printf("Falha: Lista vazia ou erro na remocao.\n");
      break;

    case 6:
      if (vazia(minhaLista)) {
        printf("A lista ja esta vazia.\n");
        break;
      }
      printf("Digite a idade do aluno que deseja remover: ");
      scanf("%d", &alunoTmp.idade);
      limparBuffer();
      if (removerValor(minhaLista, alunoTmp))
        printf("Sucesso: Aluno com idade %d foi removido!\n", alunoTmp.idade);
      else
        printf("Falha: Aluno com esta idade nao foi encontrado.\n");
      break;

    case 7:
      printf("Digite o indice que quer acessar: ");
      scanf("%d", &indiceBusca);
      limparBuffer();
      if (acessarIndice(minhaLista, indiceBusca, &alunoTmp)) {
        printf("Aluno encontrado no indice %d:\n", indiceBusca);
        printf("Nome: %s | Idade: %d\n", alunoTmp.nome, alunoTmp.idade);
      } else {
        printf("Indice inválido ou nao existente.\n");
      }
      break;

    case 8:
      printf("Digite a idade que quer buscar: ");
      scanf("%d", &idadeBusca);
      limparBuffer();
      if (acessarValor(minhaLista, idadeBusca, &alunoTmp)) {
        printf("Aluno com idade %d encontrado:\n", idadeBusca);
        printf("Nome: %s | Notas: P1=%.1f, P2=%.1f\n", alunoTmp.nome,
               alunoTmp.p1, alunoTmp.p2);
      } else {
        printf("Nenhum aluno com a idade %d foi encontrado.\n", idadeBusca);
      }
      break;

    case 9:
      exibirLista(minhaLista);
      break;

    case 0:
      printf("Limpando a memoria e saindo...\n");
      destruir(minhaLista);
      free(minhaLista); // Libera o ponteiro principal alocado no criar()
      break;

    default:
      printf("Opcao invalida! Tente novamente.\n");
    }
  } while (opcao != 0);

  return 0;
}
