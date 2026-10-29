#define MAX 50

struct aluno {
  int idade;
  char nome[50];
  float p1;
  float p2;
  float pj;
};

typedef struct pilha Pilha;
Pilha *cria();
int inserir(Pilha *, struct aluno);
int retira();
int acessar(Pilha *, struct aluno *);
void destruir();
