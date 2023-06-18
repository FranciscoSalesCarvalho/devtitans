/**
 * @brief compara duas listas encadeadas e
retorna 1 se forem iguais e 0 caso contrário.
 *
 * @param l1
 * @param l2
 * @return int
 */
int igual (Lista* l1, Lista* l2) {
    if (l1 == NULL && l2 == NULL) return 1;

    if (l1 != NULL && l2 != NULL) {
        return (l1->info == l2->info
                && identicalTrees(l1->prox, l2->prox));
    }

    return 1;
}