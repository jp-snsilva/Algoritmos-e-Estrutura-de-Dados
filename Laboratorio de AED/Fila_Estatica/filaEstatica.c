#include "filaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

struct fila {
  int qtd, inicio, fim;
  struct aluno dados[MAX];
};

Fila *cria_fila() {
  Fila *fe;
  fe = (Fila *)malloc(sizeof(Fila));
  if (fe != NULL) {
    fe->qtd = 0;
    fe->inicio = 0;
    fe->fim = 0;
  }
  return fe;
}

int inserir_fila(Fila *fe, struct aluno elem) {
  if (fe == NULL)
    return 0;
  if (fe->qtd != MAX) {
    fe->dados[fe->fim] = elem;
    fe->fim = (fe->fim + 1) % MAX;
    fe->qtd++;
    return 1;
  } else
    return -1;
}

int remover_fila(Fila *fe) {
  if (fe == NULL)
    return 0;
  if (fe->qtd != 0) {
    fe->inicio = (fe->inicio + 1) % MAX;
    fe->qtd--;
    return 1;
  } else
    return -1;
}

int acessar_fila(Fila *fe, struct aluno *elem) {
  if (fe == NULL) {
    return 0;
  } else {
    *elem = fe->dados[fe->inicio];
    return 1;
  }
}

void destruir_fila(Fila *fe) { free(fe); }
