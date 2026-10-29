
struct aluno {
  int idade;
  char nome[50];
  float p1;
  float p2;
  float pj;
};

typedef struct elemento *Pilha;

Pilha *criar();
int vazia(Pilha *);
int cheio(Pilha *);
int tamanho(Pilha *);
int acessar(Pilha *, struct aluno *);
int inserir(Pilha *, struct aluno);
int remover(Pilha *);
void destruir(Pilha *);
