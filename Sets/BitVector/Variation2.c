//using bit fields inside a struct
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    unsigned int field : 8;
} Set;

void initialize(Set *set);
void insert(Set *set, int element);
void delete(Set *set, int element);
bool find(Set set, int element);
Set Union(Set A, Set B);
Set intersection(Set A, Set B);
Set difference(Set A, Set B);
void display(Set set); //i think this should be Set instead of unsigned char

int main(){
    Set A, B ,C;
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

    C = intersection(A, B);
    display(C);

    C = difference(A, B);
    display(C);

    return 0;
}

void initialize(Set *set){
    set->field = 0;
}

void insert(Set *set, int element){
    if(element >= 0 && element < 8){
        set->field |= (1 << element);
    }
}

void delete(Set *set, int element){
    if(element >= 0 && element < 8){
        set->field &= ~(1 << element);
    }
}

bool find(Set set, int element){
    if(element >= 0 && element < 8){
        unsigned mask = 1 << element;
        return (set.field & mask) != 0;
    }
}

Set Union(Set A, Set B){
    Set result;
    result.field = A.field | B.field;

    return result;
}

Set intersection(Set A, Set B){
    Set result;
    result.field = A.field & B.field;

    return result;
}

Set difference(Set A, Set B){
    Set result;
    result.field = A.field & ~B.field;

    return result;
}

void display(Set set){
    int x;
    printf("{ ");
    for(x = 0; x < 8; x++){
        if(set.field & 1 << x){
            printf("%d ", x);
        }
    }
    printf("}\n");
}
