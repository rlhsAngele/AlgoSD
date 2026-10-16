
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

/*TABLEAU*/
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
    if (A == NULL || x == NULL ||
        i < 0 || i >= A->size) {
        return 0;
    }

    *x = A->tab[i];
    return 1;
}

int Insertion(array A, int i, int x) {
    if (A == NULL || i < 0 ||
        i > A->size || A->size >= 100) {
        return 0;
    }

    for (int j = A->size; j > i; j--) {
        A->tab[j] = A->tab[j - 1];
    }

    A->tab[i] = x;
    A->size++;

    return 1;
}

int Deletion(array A, int i) {
    if (A == NULL || i < 0 || i >= A->size) {
        return 0;
    }

    for (int j = i; j < A->size - 1; j++) {
        A->tab[j] = A->tab[j + 1];
    }

    A->size--;

    return 1;
}

void print_array(array A) {
    if (A == NULL) return;

    printf("{");

    for (int i = 0; i < A->size; i++) {
        printf("%i", A->tab[i]);

        if (i < A->size - 1) {
            printf(" ");
        }
    }

    printf("}\n");
}


/*STACK*/

struct Stack {
    int tab[100];
    int size;
};

typedef struct Stack* stack;

stack Stack_Create(void) {
    stack S = malloc(sizeof(struct Stack));

    if (S != NULL) {
        S->size = 0;
    }

    return S;
}

int Push(stack S, int x) {
    if (S == NULL || S->size >= 100) {
        return 0;
    }

    S->tab[S->size] = x;
    S->size++;

    return 1;
}

int Pop(stack S, int *x) {
    if (S == NULL || x == NULL || S->size == 0) {
        return 0;
    }

    S->size--;
    *x = S->tab[S->size];

    return 1;
}

int Peek(stack S, int *x) {
    if (S == NULL || x == NULL || S->size == 0) {
        return 0;
    }

    *x = S->tab[S->size - 1];

    return 1;
}

void print_stack(stack S) {
    if (S == NULL) return;

    printf("Top -> ");

    for (int i = S->size - 1; i >= 0; i--) {
        printf("%i ", S->tab[i]);
    }

    printf("\n");
}


/*QUEUE */

struct Queue {
    int tab[100];
    int front;
    int size;
};

typedef struct Queue* queue;

queue Queue_Create(void) {
    queue Q = malloc(sizeof(struct Queue));

    if (Q != NULL) {
        Q->front = 0;
        Q->size = 0;
    }

    return Q;
}

int Enqueue(queue Q, int x) {
    if (Q == NULL || Q->size >= 100) {
        return 0;
    }

    int rear = (Q->front + Q->size) % 100;

    Q->tab[rear] = x;
    Q->size++;

    return 1;
}

int Dequeue(queue Q, int *x) {
    if (Q == NULL || x == NULL || Q->size == 0) {
        return 0;
    }

    *x = Q->tab[Q->front];

    Q->front = (Q->front + 1) % 100;
    Q->size--;

    return 1;
}

int Front(queue Q, int *x) {
    if (Q == NULL || x == NULL || Q->size == 0) {
        return 0;
    }

    *x = Q->tab[Q->front];

    return 1;
}

void print_queue(queue Q) {
    if (Q == NULL) return;

    printf("Front -> ");

    for (int i = 0; i < Q->size; i++) {
        int index = (Q->front + i) % 100;
        printf("%i ", Q->tab[index]);
    }

    printf("<- Rear\n");
}




int main(void) {
    int x;

    /*Tableau*/
    array A = Array_Create();

    if (A == NULL) return 1;

    Insertion(A, 0, 1);
    Insertion(A, 1, 2);
    Insertion(A, 2, 3);

    printf("Tableau : ");
    print_array(A);

    Insertion(A, 1, 10);

    printf("insertion : ");
    print_array(A);

    Deletion(A, 2);

    printf("suppression : ");
    print_array(A);

    if (Direct_Access(A, 1, &x)) {
        printf("element a l'indice 1 : %i\n", x);
    }


    /*Stack*/
    stack S = Stack_Create();

    if (S == NULL) {
        free(A);
        return 1;
    }

    Push(S, 10);
    Push(S, 20);
    Push(S, 30);

    printf("\nStack : ");
    print_stack(S);

    if (Peek(S, &x)) {
        printf("peek : %i\n", x);
    }

    if (Pop(S, &x)) {
        printf("Element pop : %i\n", x);
    }

    printf("Stack Pop : ");
    print_stack(S);


    /*Queue*/
    queue Q = Queue_Create();

    if (Q == NULL) {
        free(S);
        free(A);
        return 1;
    }

    Enqueue(Q, 100);
    Enqueue(Q, 200);
    Enqueue(Q, 300);

    printf("\nQueue : ");
    print_queue(Q);

    if (Front(Q, &x)) {
        printf("front : %i\n", x);
    }

    if (Dequeue(Q, &x)) {
        printf("element retire : %i\n", x);
    }

    printf("Dequeue : ");
    print_queue(Q);

    return 0;
}
