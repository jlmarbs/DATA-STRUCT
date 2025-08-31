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

//will add functionalities later
void insertSorted(LIST *LL, int data);
void insertPos(LIST *LL, int data, int pos);
void deletePos(LIST *LL, int data);

int main(){

    LIST myList;
    initializeList(&myList);

    insertFirst(&myList, 3);
    insertFirst(&myList, 2);
    displayList(myList);

    insertLast(&myList, 4);
    displayList(myList);

    deleteFirst(&myList);
    displayList(myList);

    deleteLast(&myList);
    displayList(myList);

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
    LIST *trav, newNode;

    for(trav = LL; *trav != NULL; trav = &(*trav)->link){}

    newNode = (LIST)malloc(sizeof(struct node));
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
    LIST temp, *trav;

    if(*LL != NULL){
        for(trav = LL; (*trav)->link != NULL; trav = &(*trav)->link){}
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    }
}

void displayList(LIST LL){
    LIST trav;

    for(trav = LL; trav != NULL; trav = trav->link){
        printf("%d ", trav->elem);
    }
    printf("\n");
}

void insertSorted(LIST *LL, int data){

}

void insertPos(LIST *LL, int data, int pos){

}

void deletePos(LIST *LL, int data){
    LIST *trav;
    LIST temp;

    for(trav = LL; *trav != NULL && (*trav)->elem != data; trav = &(*trav)->link){}

    if(*LL != NULL){
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}