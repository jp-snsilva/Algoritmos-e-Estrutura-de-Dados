struct aluno {
  int idade;
  char nome[50];
  float p1;
  float p2;
  float pj;
};

typedef struct elemento *Lista;

Lista *criar();
void destruir(Lista *);
int tamanho(Lista *);
int cheio(Lista *);
int vazia(Lista *);
int inserirInicio(Lista *, struct aluno);
int inserirFinal(Lista *, struct aluno);
int inserirOrdenado(Lista *, struct aluno);
int removerInicio(Lista *);
int removerFim(Lista *);
int removerValor(Lista *, struct aluno);
int acessarIndice(Lista *, int, struct aluno *);
int acessarValor(Lista *, int, struct aluno *);
