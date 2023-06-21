#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
  return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad)
{
  Arv* p=(Arv*)malloc(sizeof(Arv));
  p->info = c;
  p->esq = sae;
  p->dir = sad;
  return p;
}

int vazia(Arv* a)
{
  return a==NULL;
}

Arv* libera (Arv* a){
  if (!vazia(a)){
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}

void imprime_pre (Arv* a)
{
    if (a == NULL) return;
    printf("%d ", a->info);
    imprime_pre (a->esq);
    imprime_pre (a->dir);
}

void imprime_in (Arv* a)
{
    if (a == NULL) return;
    imprime_in(a->esq);
    printf("%d ", a->info);
    imprime_in(a->dir);
}

void imprime_pos(Arv* a)
{
    if (a == NULL) return;
    imprime_pos(a->esq);
    imprime_pos(a->dir);
    printf("%d ", a->info);
}

int main()
{
    Arv *root = cria(45, NULL, NULL);
    root->esq = cria(5, NULL, NULL);
    root->dir = cria(80, NULL, NULL);
    /*resposta questão 3*/
    root->dir->esq = cria(3, NULL, NULL);
    root->dir->esq->esq = cria(66, NULL, NULL);
    root->dir->esq->dir = cria(31, NULL, NULL);
    /*fim resposta 3*/
    root->dir->dir = cria(40, NULL, NULL);
    root->esq->esq = cria(12, NULL, NULL);
    root->esq->dir = cria(34, NULL, NULL);
    root->esq->dir->dir = cria(67, NULL, NULL);

    /*resposta questão 4*/
    libera(root->esq->dir);
    root->esq = cria(5, NULL, NULL);
    /*fim resposta 4*/

    imprime_pre(root);
    printf("\n");
    imprime_pos(root);
    printf("\n");
    imprime_in(root);

    return 0;
}