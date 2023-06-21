#include <stdio.h>
#include <stdlib.h>

struct arv
{
  int info;
  struct arv *esq;
  struct arv *dir;
};

typedef struct arv Arv;

Arv *busca(Arv *r, int v)
{
  if (r == NULL)
    return NULL;
  else if (r->info > v)
    return busca(r->esq, v);
  else if (r->info < v)
    return busca(r->dir, v);
  else
    return r;
}

Arv *insere(Arv *a, int v)
{
  if (a == NULL)
  {
    a = (Arv *)malloc(sizeof(Arv));
    a->info = v;
    a->esq = a->dir = NULL;
  }
  else if (v < a->info)
    a->esq = insere(a->esq, v);
  else /* v < a->info */
    a->dir = insere(a->dir, v);
  return a;
}

int vazia(Arv* a)
{
  return a==NULL;
}

Arv *libera(Arv *a)
{
  if (!vazia(a))
  {
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a);        /* libera raiz */
  }
  return NULL;
}

void imprime_in(Arv *r)
{
  if (vazia(r)) return;
  imprime_in(r->esq);
  printf("%d ", r->info);
  imprime_in(r->dir);
}

int main(void)
{
  Arv *root = NULL;
  int elements[] = {1, 2, 3, 5, 15, 7};
  int busca_numbers[] = {2, 8};

  for (register int i = 0; i < 6; i++)
  {
    root = insere(root, elements[i]);
    imprime_in(root);
    printf("\n");
  }

  for (register int i = 0; i < 2; i++)
  {
    if (busca(root, busca_numbers[i]) == NULL)
    {
      printf("Elemento %d não encontrado\n", busca_numbers[i]);
    } else {
      printf("Elemento %d encontrado\n", busca_numbers[i]);
    }
  }

  return 0;
}
