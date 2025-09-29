//using bool (in the ADT Guide)
#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void Union(Set A, Set B, Set C);
void Intersection(Set A, Set B, Set C);
void Difference(Set A, Set B, Set C);
void display(Set set);

int main(){
    Set A, B, C;
    initialize(A);
    initialize(B);
    initialize(C);

    insert(A, 1);
    insert(A, 3);
    insert(A, 5);

    insert(B, 2);
    insert(B, 4);
    insert(B, 5);

    Union(A, B, C);
    display(C);

    Intersection(A, B, C);
    display(C);

    Difference(A, B, C);
    display(C);

    return 0;
}

void initialize(Set set){
    int x;
    for(x = 0; x < ARRAY_SIZE; x++){
        set[x] = false;
    }
}

void insert(Set set, int element){
    if(element >= 0 && element < ARRAY_SIZE){
        set[element] = true;
    }
}

void delete(Set set, int element){
    if(element >= 0 && element < ARRAY_SIZE){
        set[element] = false;
    }
}

bool find(Set set, int element){
    return (element >= 0 && element < ARRAY_SIZE) ? set[element] : false;
}

void Union(Set A, Set B, Set C){
    int x;
    for(x = 0 ; x < ARRAY_SIZE; x++){
        C[x] = A[x] | B[x];
    }
}

void Intersection(Set A, Set B, Set C){
    int x;
    for(x = 0 ; x < ARRAY_SIZE; x++){
        C[x] = A[x] & B[x];
    }
}

void Difference(Set A, Set B, Set C){
    int x;
    for(x = 0 ; x < ARRAY_SIZE; x++){
        C[x] = A[x] & ~B[x];
    }
}

void display(Set set){
    int x;
    printf("{ ");
    for(x = 0; x < ARRAY_SIZE; x++){
        if(set[x]){
            printf("%d ", x);
        }
    }
    printf("}\n");
}
