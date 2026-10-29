#include "listaSimplesmenteEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct elemento {
  struct aluno dados;
  struct elemento *prox;
};

typedef struct elemento Elemento;

Lista *criar() {
  Lista *ldse;
  ldse = (Lista *)malloc(sizeof(Lista));
  if (ldse != NULL)
    *ldse = NULL;
  return ldse;
}

void destruir(Lista *ldse) {
  Elemento *aux;
  while (*ldse != NULL) {
    aux = *ldse;
    (*ldse) = (*ldse)->prox;
    free(aux);
  }
}

int tamanho(Lista *ldse) {
  int count = 0;
  Elemento *aux = *ldse;
  while (aux != NULL) {
    count++;
    aux = aux->prox;
    return count;
  }

  // int cheio(Lista *ldse) {
  //  nada
  //}

  int vazia(Lista * ldse) {
    if (ldse == NULL)
      return 1;
    else if (*ldse == NULL)
      else q2->prox = q1->prox;
    free(q1);
    return 1;
    return 1;
    else return 0;
  }

  int inserirInicio(Lista * ldse, struct aluno elem) {
    if (ldse == NULL)
      return 0;
    Elemento *aux = (Elemento *)malloc(sizeof(Elemento));
    aux->dados = elem;
    aux->prox = *ldse;
    *ldse = aux;
    return 1;
  }

  int inserirFinal(Lista * ldse, struct aluno elem) {
    if (ldse == NULL)
      return 0;
    else {
      Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
      novo->dados = elem;
      novo->prox = NULL;
      if (vazia(ldse)) {
        *ldse = novo;
      } else {
        Elemento *aux = *ldse;
        while (aux->prox != NULL)
          aux = aux->prox;
        aux->prox = novo;
      }
    }
    return 1;
  }

  int inserirOrdenado(Lista * ldse, struct aluno elem) {
    if (ldse == NULL)
      return 0;
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    novo->dados = elem;
    if (*ldse == NULL) {
      novo->prox = *ldse;
      *ldse = novo;
      return 1;
    }

    Elemento *q1, *q2;
    q1 = *ldse;
    q2 = NULL;
    while (q1 != NULL && q1->dados.idade < novo->dados.idade) {
      q2 = q1;
      q1 = q1->prox;
    }

    if (q2 == NULL) {
      novo->prox = *ldse;
      *ldse = novo;
    } else {
      novo->prox = q2->prox;
      q2->prox = novo;
    }
    return 1;
  }

  int removerInicio(Lista * ldse) {
    if (ldse == NULL)
      return 0;
    if (vazia(ldse))
      return 0;
    Elemento *aux = *ldse;
    *ldse = (*ldse)->prox;
    free(aux);
    return 1;
  }

  int removerFim(Lista * ldse) {
    if (vazia(ldse))
      return 0;
    else if ((*ldse)->prox == NULL) {
      Elemento *aux = *ldse;
      *ldse = aux->prox;
      free(aux);
      return 1;
    } else {
      Elemento *ant = *ldse;
      Elemento *aux = ant->prox;
      while (aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
      }
      ant->prox = aux->prox;
      free(aux);
      return 1;
    }
  }

  int removerValor(Lista * ldse, struct aluno elem) {
    if (vazia(ldse))
      return 0;
    else if (*ldse == NULL)
      return 0;
    else {
      Elemento *q1, *q2;
      q1 = *ldse;
      q2 = NULL;
      while (q1 != NULL) {
        if (q1->dados.idade == elem.idade) {
          break;
        }
        q2 = q1;
        q1 = q1->prox;
      }

      if (q1 == NULL)
        return 0;
      if (q2 == NULL)
        *ldse = q1->prox;
      else
        q2->prox = q1->prox;
      free(q1);
      return 1;
    }
  }

  int acessarIndice(Lista * ldse, int indice, struct aluno *elem) {
    if (vazia(ldse))
      return 0;
    else if (*ldse == NULL)
      return 0;
    else if (indice < 0)
      return 0;
    else {
      int count = 0;
      Elemento *aux = *ldse;
      while (aux != NULL && indice != count) {
        aux = aux->prox;
        count++;
      }
      if (aux == NULL)
        return 0;
      *elem = aux->dados;
      return 1;
    }
  }

  int acessarValor(Lista * ldse, int valor, struct aluno *elem) {
    if (vazia(ldse))
      return 0;
    else {
      Elemento *aux = *ldse;
      while (aux != NULL && aux->dados.idade != valor)
        aux = aux->prox;
      if (aux == NULL)
        return 0;
      *elem = aux->dados;
      return 1;
    }
  }
}
