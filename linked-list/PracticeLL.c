#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *link;
    int elem;
} *LIST;

void initializeList(LIST *LL);
void insertFirst(LIST *LL, int data);
void insertLast(LIST *LL, int data);
void deleteFirst(LIST *LL);
void deleteLast(LIST *LL);
void displayList(LIST LL);
void insertSorted(LIST *LL, int data);
void delete(LIST *LL, int data);

int main(){

    LIST L;
    initializeList(&L);

    insertFirst(&L, 1);
    insertFirst(&L, 2);
    displayList(L);

    insertLast(&L, 3);
    displayList(L);

    deleteFirst(&L);
    displayList(L);

    deleteLast(&L);
    displayList(L);

    insertSorted(&L, 3);
    insertSorted(&L, 2);
    displayList(L);

    delete(&L, 2);
    displayList(L);

    return 0;
}

void initializeList(LIST *LL){
    *LL = NULL;
}

void insertFirst(LIST *LL, int data){
    LIST newNode = (LIST)malloc(sizeof(struct node));

    if(newNode != NULL){
        newNode->elem = data;
        newNode->link = *LL;
        *LL = newNode;
    }
}

void insertLast(LIST *LL, int data){
    LIST *trav;

    for(trav = LL; *trav != NULL; trav = &(*trav)->link){}

    LIST newNode = (LIST)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = data;
        newNode->link = *trav;
        *trav = newNode;
    }
}

void deleteFirst(LIST *LL){
    LIST temp;

    if(*LL != NULL){
        temp = *LL;
        *LL = (*LL)->link;
        free(temp);
    }
}

void deleteLast(LIST *LL){
    LIST temp;
    LIST *trav;

    if(*LL != NULL){
        for(trav = LL; (*trav)->link != NULL ; trav = &(*trav)->link){}

        temp = *trav;
        *trav = NULL;
        free(temp);
    }
}

void displayList(LIST LL){
    LIST trav;

    for(trav = LL; trav != NULL; trav = (trav)->link){
        printf("%d ", trav->elem);
    }
    printf("\n");
}

void insertSorted(LIST *LL, int data){
    LIST *trav;

    for(trav = LL; *trav != NULL && (*trav)->elem < data; trav = &(*trav)->link){}

    LIST newNode = (LIST)malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = data;
        newNode->link = *trav;
        *trav = newNode;
    }
}

void delete(LIST *LL, int data){
    LIST *trav;
    LIST temp;

    if(*LL != NULL){
        for(trav = LL; *trav != NULL && (*trav)->elem != data; trav = &(*trav)->link){}

        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    }
}