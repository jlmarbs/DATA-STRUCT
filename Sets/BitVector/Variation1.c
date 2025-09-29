// using a char element holding an integer value
#include <stdio.h>
#include <stdbool.h>

void initialize(unsigned char *set);
void insert(unsigned char *set, int element);
void delete(unsigned char *set, int element);
bool find(unsigned char set, int element);
unsigned char Union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main(){
    unsigned char A, B, C;
    initialize(&A);
    initialize(&B);
    initialize(&C);

    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);

    insert(&B, 2);
    insert(&B, 4);
    insert(&B, 5);

    C = Union(A, B);
    display(C);

    // delete(&B, 5);

    C = intersection(A, B);
    display(C);

    C = difference(A, B);
    display(C);

    return 0;
}

void initialize(unsigned char *set){
    *set = 0;
}

void insert(unsigned char *set, int element){
    if(element >= 0 && element < 8){
        unsigned char mask = 1 << element;
        *set |= mask;
    }
}

void delete(unsigned char *set, int element){
    if(element >= 0 && element < 8){
        unsigned char mask = 1 << element;
        *set &= ~mask;
    }
}

bool find(unsigned char set, int element){
    if(element >= 0 && element < 8){
        unsigned mask = 1 << element;
        return (set & mask) != 0;
    }
}

unsigned char Union(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B){
    return A & ~B;
}

void display(unsigned char set){
    int x;
    printf("{ ");
    for(x = 0; x < 8; x++){
        if(set & 1 << x){
            printf("%d ", x);
        }
    }
    printf("}\n");
}
