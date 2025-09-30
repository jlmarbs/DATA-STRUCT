#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} dType, *SET;

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
    insert(&A, 3);
    insert(&A, 5);
    display(A);

    insert(&B, 2);
    insert(&B, 3);
    insert(&B, 4);
    display(B);

    Union(A, B, &C);
    display(C);

    Intersection(A, B, &C);
    display(C);

    Difference(A, B, &C);
    display(C);

    return 0;
}

void initialize(SET *set){
    *set = NULL;
}

void insert(SET *set, int element) {
    if (find(*set, element)) {
        return;
    }

    SET newNode = (SET)malloc(sizeof(struct node));
    if (newNode != NULL){
        newNode->data = element;
        newNode->next = NULL;

        if (*set == NULL) {
            *set = newNode;
        } else {
            SET trav = *set;
            while (trav->next != NULL) {
                trav = trav->next;
            }
        trav->next = newNode;
        }
    }
}

void delete(SET *set, int element){
    SET *trav, temp;
    for(trav = set; *trav != NULL && (*trav)->data != element; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

bool find(SET set, int element){
    SET trav;
    for(trav = set; trav != NULL; trav = trav->next){
        if(trav->data == element){
            return true;
        }
    }
    return false;
}

void Union(SET A, SET B, SET *C){
    initialize(C);
    SET travA, travB;

    for(travA = A; travA != NULL; travA = travA->next){
        insert(C, travA->data);
    }
    for(travB = B; travB != NULL; travB = travB->next){
        insert(C, travB->data);
    }
}

void Intersection(SET A, SET B, SET *C){
    initialize(C);
    SET trav;

    for(trav = A; trav != NULL; trav = trav->next){
        if(find(B, trav->data)){
            insert(C, trav->data);
        }
    }
}

void Difference(SET A, SET B, SET *C){
    initialize(C);
    SET trav;

    for(trav = A; trav != NULL; trav = trav->next){
        if(!find(B, trav->data)){
            insert(C, trav->data);
        }
    }
}

void display(SET set){
    SET trav;
    printf("{ ");
    for(trav = set; trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
    printf("}\n");
}