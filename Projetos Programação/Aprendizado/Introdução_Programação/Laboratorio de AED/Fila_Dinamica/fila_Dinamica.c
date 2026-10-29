#include "fila_Dinamica.h"
#include <stdlib.h>

struct elemento {
  struct aluno dados;
  struct elemento *prox;
};

typedef struct elemento Elemento;

struct fila {
  struct elemento *inicio;
  struct elemento *fim;
  int tamanho_fila;
};

Fila *criar() {
  Fila *fd = (Fila *)malloc(sizeof(Fila));
  fd->tamanho_fila = 0;
  fd->inicio = NULL;
  fd->fim = NULL;
  if (fd == NULL)
    return 0;
  return fd;
}

int vazia(Fila *fd) {
  if (fd->inicio == NULL)
    return 1;
  return 0;
}

// int cheia(Fila *fd){
// nada
//}

// tamanho implementado no nó descritor;
// mas também é possível fazer assim:
// int tamanho(Fila *fd){
//   Elemento *aux = fd->inicio;
//   int count = 0;
//   while (aux != NULL){
//    count++;
//    aux = aux->prox;
//   }
// }

int tamanho(Fila *fd) { return fd->tamanho_fila; }

int inserir(Fila *fd, struct aluno elem) {
  Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
  aux->dados = elem;
  aux->prox = NULL;
  if (vazia(fd))
    fd->inicio = aux;
  else
    (fd->fim)->prox = aux;

  fd->fim = aux;
  fd->tamanho_fila++;
  return 1;
}

int remover(Fila *fd) {
  if (vazia(fd))
    return 0;
  Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
  aux = fd->inicio;
  fd->inicio = (fd->inicio)->prox;
  free(aux);
  return 1;
}

int acessar(Fila *fd, struct aluno *elem) {
  if (vazia(fd))
    return 0;
  *elem = (fd->inicio)->dados;
  return 1;
}

void destruir(Fila *fd) {
  if (vazia(fd))
    return;
  Elemento *aux = fd->inicio;
  while (aux != NULL) {
    Elemento *temp = aux;
    aux = aux->prox;
    free(temp);
  }
  fd->inicio = NULL;
  fd->fim = NULL;
  return;
}
