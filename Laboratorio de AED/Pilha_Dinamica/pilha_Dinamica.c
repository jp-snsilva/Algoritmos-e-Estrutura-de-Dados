#include "pilha_Dinamica.h"
#include <stdio.h>
#include <stdlib.h>

struct elemento {
  struct aluno dados;
  struct elemento *prox;
};

typedef struct elemento Elemento;

Pilha *criar() {
  Pilha *pd = (Pilha *)malloc(sizeof(Pilha));
  if (pd == NULL)
    return 0;
  return pd;
}

int vazia(Pilha *pd) {
  if (*pd == NULL)
    return 1;
  if (pd == NULL)
    return 1;
  return 0;
}

// int cheia(Pilha* pd){
// nada;
//}

int tamanho(Pilha *pd) {
  int count = 0;
  Elemento *aux = *pd;
  while (aux != NULL) {
    count++;
    aux = aux->prox;
  }
  return count;
}

int acessar(Pilha *pd, struct aluno *elem) {
  if (*pd == NULL)
    return 0;
  if (pd == NULL)
    return 0;
  *elem = (*pd)->dados;
  return 1;
}

int inserir(Pilha *pd, struct aluno elem) {
  Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
  aux->dados = elem;
  aux->prox = *pd;
  *pd = aux;
  return 1;
}

int remover(Pilha *pd) {
  if (vazia(pd))
    return 0;
  Elemento *aux = *pd;
  *pd = (*pd)->prox;
  free(aux);
  return 1;
}

void destruir(Pilha *pd) {
  if (vazia(pd))
    return;
  Elemento *aux = *pd;
  while (*pd != NULL) {
    aux = *pd;
    *pd = (*pd)->prox;
    free(aux);
  }
  return;
}
