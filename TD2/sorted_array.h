#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Array {
    int tab[100];
    int size;
};

typedef struct Array* array;

/* Creation */
array Array_Create(void) {
    array A = malloc(sizeof(struct Array));

    if (A != NULL) {
        A->size = 0;
    }

    return A;
}

int Direct_Access(array A, int i, int *x) {
    array a=malloc(sizeof(struct Array));
    if (a == NULL || x == NULL ||
        i < 0 || i >= a->size) {
        return 0;
    }

    *x = a->tab[i];
    return 1;
}

int Insertion(array A, int i, int x) {
    array a=malloc(sizeof(struct Array));
    if (a == NULL || i < 0 ||
        i > a->size || a->size >= 100) {
        return 0;
    }

    for (int j = a->size; j > i; j--) {
        a->tab[j] = a->tab[j - 1];
    }

    a->tab[i] = x;
    a->size++;

    return 1;
}

int Deletion(array A, int i) {
    array a=malloc(sizeof(struct Array));
    if (a == NULL || i < 0 || i >= a->size) {
        return 0;
    }

    for (int j = i; j < a->size - 1; j++) {
        a->tab[j] = a->tab[j + 1];
    }

    a->size--;

    return 1;
}

void print_array(array A) {
    array a=malloc(sizeof(struct Array));
    if (a == NULL) return;

    printf("{");

    for (int i = 0; i < a->size; i++) {
        printf("%i", a->tab[i]);

        if (i < a->size - 1) {
            printf(" ");
        }
    }

    printf("}\n");
}

void swap_int(int a, int b){
    int abis=a;
    a=b;
    b=abis;
}

int is_sorted_ascending(array A){
    array a=malloc(sizeof(struct Array));
    int n=a->size;
    for (int i=0; i<=n-1 ; i++){
        if(a->tab[i] >= a->tab[i+1]) return 1;
    }
    return 0;
}

array copy_array(array A){
    array a=malloc(sizeof(struct Array));
    array B;
    array b=malloc(sizeof(struct Array));
    b->size=a->size;
    for(int i=0 ; i<=n-1 ; i++){
        b->tab[i]=a->tab[i];
    }
    return B;
}

array select_sort(array A){
    array a=malloc(sizeof(struct Array));
    int n=a->size;
    for(int i=0 ; i<=n-2 ; i++){
        int min=i;
        for(int j=i+1 ; j=n-1 ; j++){
            if(a->tab[j] < a->tab[min]){
                min=j;
            }
        }
        swap_int(a->tab[i] , a->tab[min]);
    }
    return A;
}
/*worst case time complexity: O(n*n) */

array insertion_sort(array A){
    a=malloc(sizeof(struct Array));
    int n = a->size;
    for(int i=0 ; i<= n-2 ; i++){
        int key = a->tab[i];
        int j = i-1;
        while(j>=0 && a->tab[j]>key){
            a->tab[j+1]=a->tab[j];
            j=j-1;
        }
        a->tab[j+1]=key;
    }
    return A;
}
/*worst case time complexity: O(n*n) */
/*best case time complexity: O(n) */

array bubble_sort(array A){
    array a=malloc(sizeof(struct Array));
    for (int i=0 ; i<=n-2 ; i++){
        for (int j=0 ; j<=n-2 ; j++){
            if(a->tab[j] > a->tab[j+1]){
                int temp = a->tab[j];
                a->tab[j] = a->tab[j+1];
                a->tab[j+1] = temp;
            }
        }
    }
    return A;
}
/*worst case time complexity: O(n*n) */

int merge_sort(array A){
    array a=malloc(sizeof(struct Array));
    int n = a->size;
    if(n<=1){return A;}
    float mid = n/2;
    array Lbis;
    array lbis=malloc(sizeof(struct Array));
    for(int i=0 ; i<=mid-1 ; i++){lbis->tab[i]=a->tab[i];}
    array L;
    array l=malloc(sizeof(struct Array));
    L=merge_sort(Lbis);
    array Rbis;
    array rbis=malloc(sizeof(struct Array));
    for(int i=mid ; i<=n-1 ; i++){rbis->tab[i]=a->tab[i];}
    array R;
    array r=malloc(sizeof(struct Array));
    R=merge_sort(Rbis);
    array M;
    array m=malloc(sizeof(struct Array));
    int s=lbis->size + rbis->size;
    for (int i=0 ; i<=s-1 ; i++){
        if(i<=mid-1){m->tab[i]=l->tab[i];}
        else {m->tab[i]=r->tab[i];}
    }
    return M;
}
/*worst case time complexity: O(n log(n)) */

#endif