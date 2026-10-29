#define MAX 50

struct aluno {
  int matricula;
  char nome[50];
  float p1;
  float p2;
  float pj;
};

typedef struct fila Fila;

Fila *cria_fila();
int inserir_fila(Fila *, struct aluno);
int remover_fila(Fila *);
int acessar_fila(Fila *, struct aluno *);
void destruir_fila(Fila *);
