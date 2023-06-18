#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa(void) {
    return NULL;
}

Lista* insere(Lista* l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void imprime(Lista* l) {
    Lista* p;
    printf("Lista: ");
    for (p = l; p != NULL; p = p->prox)
        printf("%d ", p->info);
    printf("\n");
}

void libera (Lista* l)
{
    Lista* p = l;
    while (p != NULL)
    {
    Lista* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento*/
    free(p); /* libera a mem�ria apontada por p */
    p = t; /* faz p apontar para o pr�ximo */
    }
}

int igual (Lista* l1, Lista* l2) {
    if (l1 == NULL && l2 == NULL) return 1;

    if (l1 != NULL && l2 != NULL) {
        return (l1->info == l2->info
                && identicalTrees(l1->prox, l2->prox));
    }

    return 1;
}

int main() {
    Lista* L1, *L2;       /* declara duas listas nao iniciadas */
    L1 = inicializa();   /* inicia lista vazia */
    L1 = insere(L1, 23); /* insere na lista o elemento 23 */
    L1 = insere(L1, 45); /* insere na lista o elemento 45 */
    L1 = insere(L1, 56); /* insere na lista o elemento 56 */
    L1 = insere(L1, 78); /* insere na lista o elemento 78 */
    imprime(L1);         /* imprime: 78 56 45 23 */

    L2 = inicializa();   /* inicia lista vazia */
    L2 = insere(L2, 23); /* insere na lista o elemento 23 */
    L2 = insere(L2, 45); /* insere na lista o elemento 45 */
    L2 = insere(L2, 56); /* insere na lista o elemento 56 */
    imprime(L2);         /* imprime: 56 45 23 */

    if (igual(L1, L2))
        printf("L1 e L2 sao iguais\n");
    else
        printf("L1 e L2 sao diferentes\n");

    L2 = insere(L2, 78); /* insere na lista o elemento 78 */
    imprime(L1);         /* imprime: 78 56 45 23 */
    imprime(L2);         /* imprimw: 78 56 45 23 */

    if (igual(L1, L2))
        printf("L1 e L2 sao iguais\n");
    else
        printf("L1 e L2 sao diferentes\n");

    libera(L1);
    libera(L2);

    return 0;
}