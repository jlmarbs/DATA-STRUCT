#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main(){
    Etype testList;
    Etype sortedList;
    initialize(&testList);
    initialize(&sortedList);

    insertPos(&testList, 3, 0);
    insertPos(&testList, 9, 1);
    insertPos(&testList, 2, 2);
    insertPos(&testList, 1, 2);
    display(&testList);

    deletePos(&testList, 2);
    display(&testList);

    insertSorted(&sortedList, 3);
    insertSorted(&sortedList, 9);
    insertSorted(&sortedList, 2);
    insertSorted(&sortedList, 1);
    display(&sortedList);

    locate(&sortedList, 1);
    retrieve(&sortedList, 3);

    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    int x;

    if(L->count < MAX){
        if(position >= 0 && position <= L->count){
            for(x = L->count; x > position - 1; x--){
                L->elem[x] = L->elem[x - 1];
            }
            L->elem[position] = data;
            L->count++;
        }
    }
}

void deletePos(EPtr L, int position){
    int x;
    
    if(L->count > 0){
        if(position >= 0 && position <= L->count){
            for(x = position; x < L->count; x++){
                L->elem[x] = L->elem[x + 1];
            }
            L->count--;
        }
    }
}

int locate(EPtr L, int data){
    int x;

    for(x = 0; x < L->count; x++){
        if(L->elem[x] == data){
            return x;
        }
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if(position >= 0 && position < L->count){
        return L->elem[position];
    }
    return -1;
}

void insertSorted(EPtr L, int data){
    int x;
    int pos;

    if(L->count < MAX){
        for(pos = 0; pos < L->count; pos++){
            if(L->elem[pos] >= data){
                break; //could do while loop to remove this break statement
            }
        }
        for(x = L->count; x > pos; x--){
            L->elem[x] = L->elem[x - 1];
        }
        L->elem[pos] = data;
        L->count++;
    }
}

void display(EPtr L){
    int x;

    for(x = 0; x < L->count; x++){
        printf("%d ", L->elem[x]);
    }
    printf("\n");
}

void makeNULL(EPtr L){
    L->count = 0;
}