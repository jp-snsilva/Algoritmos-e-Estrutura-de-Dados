
struct aluno {
  int idade;
  char nome[50];
  float p1;
  float p2;
  float pj;
};

typedef struct fila Fila;

Fila *criar();
int vazia(Fila *);
int cheia(Fila *);
int tamanho(Fila *);
int inserir(Fila *, struct aluno);
int remover(Fila *);
int acessar(Fila *, struct aluno *);
void destruir(Fila *);
