#include "pilhaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha {
  int qtd;
  struct aluno dados[MAX];
};

Pilha *cria() {
  Pilha *pe;
  pe = (Pilha *)malloc(sizeof(Pilha));
  if (pe != NULL) {
    pe->qtd = 0;
  }
  return pe;
}

int inserir(Pilha *pe, struct aluno elem) {
  if (pe->qtd != MAX) {
    pe->qtd++;
    pe->dados[pe->qtd] = elem;
    return 1;
  } else
    return -1;
}

int retira(Pilha *pe) {
  if (pe->qtd != 0) {
    pe->qtd--;
    return 1;
  } else
    return -1;
}

int acessar(Pilha *pe, struct aluno *elem) {
  if (pe == NULL || pe->qtd == 0)
    return -1;
  *elem = pe->dados[pe->qtd];
  return 1;
}

void destruir(Pilha *pe) { free(pe); }
