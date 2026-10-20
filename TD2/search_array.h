#ifndef SEARCH_ARRAY_H
#define SEARCH_ARRAY_H

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

int is_sorted_increasing(array A){
    array a=malloc(sizeof(struct Array));
    int n=a->size;
    int b=0;
    for (int i=0 ; i<=n-1 ; i++){
        if(a->tab[i] >= a->tab[i+1]) b=b+1;
    }
    if(b==0) {return 0;} else {return -1;}
}

int Linear_search(array A , int x){
    array a=malloc(sizeof(struct Array));
    int n = a->size;
    for( int i=0 ; i<=n-1 ; i++){
        if(a->tab[i]==x)return i;
    }
    return -1;
}
/*worst case time complexity: O(n) */

int min(int a, int b){
    if(a<=b) return a;
    else return b;
}

int Jump_search(array A, int x){
    array a=malloc(sizeof(struct Array));
    int n=a->size;
    int jump=floor(sqrt(n));
    int prev=0;
    if(is_sorted_increasing(A)==-1){return -1;}
    else {
        while(a->tab[min(n,jump)-1]<x){
            prev=jump;
            jump=jump+floor(sqrt(n));
            if (prev>=n) return -1;
        for(int i=prev ; i<=min(jump,n) ; i++){
            if (a->tab[i]==x) return i;
        return -1;
        }
        }
    }

}
/*worst case time complexity: O(sqrt(n)) */

int Binary_search(array A, int x){
    array a=malloc(sizeof(struct Array));
    int n=a->size;
    int low=0; int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (a->tab[mid]==x) return mid;
        if (a->tab[mid]<x) low=mid+1;
        else high=mid-1;
    return -1;
    }
}
/*worst case time complexity: O(log(n)) */

#endif