#include <stdio.h>
#include <stdlib.h>

struct arvgen {
  int info;
  struct arvgen *prim;
  struct arvgen *prox;
};
typedef struct arvgen ArvGen;


ArvGen* cria (int info)
{
  ArvGen *a =(ArvGen *)malloc(sizeof(ArvGen));
  a->info = info;
  a->prim = NULL;
  a->prox = NULL;
  return a;
}

void insere (ArvGen* a, ArvGen* f)
{
  f->prox = a->prim;
  a->prim = f;
}

void libera (ArvGen* a)
{
  ArvGen* p = a->prim;
  while (p!=NULL) {
    ArvGen* t = p->prox;
    libera(p);
    p = t;
  }
  free(a);
}

void imprime (ArvGen* a)
{
  ArvGen* p;
  printf("%d\n",a->info);
  for (p=a->prim; p!=NULL; p=p->prox)
    imprime(p);
}

int busca (ArvGen* a, char c)
{
  ArvGen* p;
  if (a->info==c)
    return 1;
  else {
    for (p=a->prim; p!=NULL; p=p->prox) {
      if (busca(p,c))
        return 1;
    }
  }
  return 0;
}

int main()
{
	ArvGen* _43 = cria(43);
  ArvGen* _22 = cria(22);
  ArvGen* _21 = cria(21);
  ArvGen* _58 = cria(58);
  ArvGen* _45 = cria(45);
  ArvGen* _66 = cria(66);
  ArvGen* _31 = cria(31);
  ArvGen* _71 = cria(71);
  ArvGen* _59 = cria(59);
  ArvGen* _12 = cria(12);
  ArvGen* _35 = cria(35);

  insere(_22, _66);
  insere(_22, _31);
  insere(_43, _22);
  insere(_43, _21);
  insere(_58, _71);
  insere(_58, _59);
  insere(_58, _12);
  insere(_43, _58);
  insere(_45, _35);
  insere(_43, _45);

  imprime(_43);

  if (busca(_43, 12)) {
    printf("Numero 12 encontrado\n");
  } else {
    printf("Numero 12 nao encontrado\n");
  }
  

  if (busca(_43, 88)) {
    printf("Numero 88 encontrado\n");
  } else {
    printf("Numero 88 nao encontrado\n");
  }

  return 0;
}
