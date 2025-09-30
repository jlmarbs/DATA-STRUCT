#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct{
    int content[MAX];
    int count;
} SET;

void initialize(SET *set);
void insert(SET *set, int element);
void delete(SET *set, int element);
bool find(SET set, int element);
void Union(SET A, SET B, SET *C);
void Intersection(SET A, SET B, SET *C);
void Difference(SET A, SET B, SET *C);
void display(SET set);

int main(){
    SET A, B, C;
    initialize(&A);
    initialize(&B);
    initialize(&C);

    insert(&A, 1);
    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);
    printf("Set A: ");
    display(A);

    insert(&B, 2);
    insert(&B, 3);
    insert(&B, 4);
    printf("Set B: ");
    display(B);

    Union(A, B, &C);
    printf("Union: ");
    display(C);

    Intersection(A, B, &C);
    printf("Intersection: ");
    display(C);

    Difference(A, B, &C);
    printf("Difference: ");
    display(C);

    return 0;
}

void initialize(SET *set){
    set->count = 0;
}

void insert(SET *set, int element){
    if(set->count < MAX && !find(*set, element)){
        set->content[set->count++] = element;
    }
}

void delete(SET *set, int element){
    int x, y;
    if(set->count != 0){
        for(x = 0; x < set->count; x++){
            if(set->content[x] == element){
                for(y = x; y < set->count - 1; y++){
                    set->content[y] = set->content[y + 1];
                }
                set->count--;
            }
        }
    }
}

bool find(SET set, int element){
    int x;
    for(x = 0; x < set.count; x++){
        if(element == set.content[x]){
            return true;
        }
    }
    return false;
}

void Union(SET A, SET B, SET *C){
    initialize(C);
    int x, y;

    for(x = 0; x < A.count; x++){
        insert(C, A.content[x]);
    }
    for(y = 0; y < B.count; y++){
        insert(C, B.content[y]);
    }
}

void Intersection(SET A, SET B, SET *C){
    initialize(C);
    int x;

    for(x = 0; x < A.count; x++){
        if(find(B, A.content[x])){
            insert(C, A.content[x]);
        }
    }
}

void Difference(SET A, SET B, SET *C){
    initialize(C);
    int x;

    for(x = 0; x < A.count; x++){
        if(!find(B, A.content[x])){
            insert(C, A.content[x]);
        }
    }
}

void display(SET set){
    int x;
    printf("{ ");
    for(x = 0; x < set.count; x++){
        printf("%d ", set.content[x]);
    }
    printf("}\n");
}