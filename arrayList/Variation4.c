#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPTR;
    int count;
    int max;
} List;


void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main(){

    List unsort;
    List sort;
    initialize(&unsort);
    initialize(&sort);

    insertPos(&unsort, 4, 0);
    insertPos(&unsort, 1, 1);
    insertPos(&unsort, 5, 2);
    insertPos(&unsort, 3, 3);
    insertPos(&unsort, 7, 2);
    insertPos(&unsort, 5, 3);
    insertPos(&unsort, 6, 3);
    insertPos(&unsort, 9, 2);
    insertPos(&unsort, 9, 0);
    insertPos(&unsort, 0, 1);
    insertPos(&unsort, 1, 1);
    insertPos(&unsort, 4, 0);
    display(&unsort);

    deletePos(&unsort, 0);
    display(&unsort);

    insertSorted(&sort, 9);
    insertSorted(&sort, 3);
    insertSorted(&sort, 6);
    insertSorted(&sort, 1);
    insertSorted(&sort, 4);
    insertSorted(&sort, 2);
    insertSorted(&sort, 43);
    insertSorted(&sort, 33);
    insertSorted(&sort, 11);
    insertSorted(&sort, 30);
    insertSorted(&sort, 3);
    insertSorted(&sort, 31);
    insertSorted(&sort, 0);
    display(&sort);

    return 0;
}

void initialize(List *L){
    L->elemPTR = (int*)malloc(sizeof(int) * LENGTH);
    if(L->elemPTR != NULL){
        L->max = LENGTH;
        L->count = 0;
    }
}

void insertPos(List *L, int data, int position){
    if(L->count >= L->max){
        resize(L);
    }
    if(position >= 0 && position <= L->count){
        int x;
        for(x = L->count; x > position; x--){
            L->elemPTR[x] = L->elemPTR[x - 1];
        }
        L->elemPTR[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position){
    if(position >= 0 && position <= L->count){
        int x;
        for(x = position; x < L->count; x++){
            L->elemPTR[x] = L->elemPTR[x + 1];
        }
        L->count--;
    }
}

int locate(List *L, int data){
    int x;
    for(x = 0; x < L->count; x++){
        if(L->elemPTR[x] == data){
            return L->elemPTR[x];
        } else{
            return -1;
        }
    }
}

int retrieve(List *L, int position){
    if(position >= 0 && position <= L->count){
        return L->elemPTR[position];
    }
}

void insertSorted(List *L, int data){
    int x, pos;
    if(L->count >= L->max){
        resize(L);
    }
    for(pos = 0; pos < L->count; pos++){
        if(L->elemPTR[pos] >= data){
            break;
        }
    }
    for(x = L->count; x > pos; x--){
        L->elemPTR[x] = L->elemPTR[x - 1];
    }
    L->elemPTR[pos] = data;
    L->count++;
}

void display(List *L){
    int x;
    for(x = 0; x < L->count; x++){
        printf("%d ", L->elemPTR[x]);
    }
    printf("\n");
}

void resize(List *L){
    int newMax = L->max * 2;
    int *newPTR = (int*)realloc(L->elemPTR, sizeof(int) * newMax);
    if(newPTR != NULL){
        L->elemPTR = newPTR;
        L->max = newMax;
    }
}

void makeNULL(List *L);