#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct cell{
    int head;
    struct cell* tail;
}* list;

#define empty NULL

list add(int h, list t){
    list l = malloc(sizeof(struct cell));
    l->head = h; l->tail = t;
    return l
}

void print_list(list l){
    list p = 1;
    printf("(");
    while (p!=empty){
        p = p->tail;
        if (p!=empty) printf(" ");
    }
    printf(")");
}

int fibonacci_n( int n ){
    if(n==0 || n==1) return n; else {return fibonacci_n(n-1)+fibonacci_n(n-2);}
}



unsigned long long fibonacci_dp(int n , unsigned long long DPFib[]){
    if (n<=1) return n;
    if (!(DPFib[n]==-1)) return DPFib[n];
    DPFib[n]=fibonacci_dp(n-1,DPFib)+fibonacci(n-2,DPFib);
    return DPFib[n];
}

list Prime_naif(int n){
    list L=NULL;
    int a=0;
    for(int i=2 ; i<=n , i++){
        for(int j=1 , j<=sqrt(n),j++){
            if(i%j==0){a=a+1;}
        }
        if(a==0){L=add(i,L);}
    }
    return L;
}

void main(){
    for (int i = 0; i < MAX; i++)
        DPFib[i] = (unsigned long long)-1;
    printf("%f",fibonacci_n(40,DPFib[]));
    printf("%f",fibonacci_dp(40,DPFib[]));
}