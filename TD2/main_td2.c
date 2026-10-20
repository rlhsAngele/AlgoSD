#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sorted_array.h"
#include "search_array.h"

int main(void){
        array A;
    A->size=3;
    A->tab[0]=1;
    A->tab[1]=2;
    A->tab[2]=3;
    print_array(A);
    printf("%i", is_sorted_increasing(A));
    printf("%i", Linear_search(A));
    printf("%i", selection_search(A));
    return 0;
}