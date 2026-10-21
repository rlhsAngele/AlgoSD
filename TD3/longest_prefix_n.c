#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array {
    int size;
    char* tab[100];
};

typedef struct Array* array;


char* longest_prefix_n(array A) {
    if (A == NULL || A->size <= 0)
        return NULL;

    // Trier les chaînes
    qsort(A->tab, A->size, sizeof(A->tab[0]), compare);

    // Premier et dernier éléments après le tri
    char* first = A->tab[0];
    char* last = A->tab[A->size - 1];

    // Calculer la longueur du préfixe commun
    int i = 0;
    while (first[i] != '\0' &&
           last[i] != '\0' &&
           first[i] == last[i]) {
        i++;
    }

    // Copier le préfixe dans une nouvelle chaîne
    char* prefix = malloc((i + 1) * sizeof(char));
    if (prefix == NULL)
        return NULL;

    strncpy(prefix, first, i);
    prefix[i] = '\0';

    return prefix;
}

int main(void) {
    struct Array B = {
        .size = 3,
        .tab = {"salu", "sala", "sali"}
    };

    array A = &B;

    print_array(A);

    char* prefix = longest_prefix_n(A);

    if (prefix != NULL) {
        printf("Prefixe commun : %s\n", prefix);
        free(prefix);
    }

    return 0;
}