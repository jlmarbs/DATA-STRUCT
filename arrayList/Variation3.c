#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main(){

    List test;
    List sorted;
    test = initialize(test);
    sorted = initialize(sorted);

    test = insertPos(test, 3, 0);
    test = insertPos(test, 4, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    test = insertPos(test, 1, 1);
    display(test);

    test = deletePos(test, 1);
    display(test);

    sorted = insertSorted(sorted, 1);
    sorted = insertSorted(sorted, 7);
    sorted = insertSorted(sorted, 2);
    sorted = insertSorted(sorted, 5);
    sorted = insertSorted(sorted, 9);
    sorted = insertSorted(sorted, 1);
    sorted = insertSorted(sorted, 2);
    sorted = insertSorted(sorted, 3);
    sorted = insertSorted(sorted, 4);
    sorted = insertSorted(sorted, 8);
    sorted = insertSorted(sorted, 6);
    display(sorted);

    return 0;
}

List initialize(List L){
    L.elemPtr = (int*)malloc(sizeof(int) * LENGTH);

    if(L.elemPtr != NULL){
        L.max = LENGTH;
    }
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    int x;

    if(L.count >= L.max){
        L = resize(L);
        printf("if you see this, realloc worked\n");
    }

    if(position >= 0 && position <= L.count){
        for(x = L.count; x > position; x--){
            L.elemPtr[x] = L.elemPtr[x - 1];
        }
        L.elemPtr[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position){
    int x;

    if(L.count > 0){
        if(position >= 0 && position <= L.count){
            for(x = position; x < L.count; x++){
                L.elemPtr[x] = L.elemPtr[x + 1];
            }
            L.count--;
        }
    }
    return L;
}

int locate(List L, int data){
    int x;

    for(x = 0; x < L.count; x++){
        if(L.elemPtr[x] == data){
            return x;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    int x;
    int pos;

    if(L.count >= L.max){
        L = resize(L);
        printf("if you see this, realloc worked\n");
    }

    for(pos = 0; pos < L.count; pos++){
        if(L.elemPtr[pos] >= data){
            break;
        }
    }
    for(x = L.count; x > pos; x--){
        L.elemPtr[x] = L.elemPtr[x - 1];
    }
    L.elemPtr[pos] = data;
    L.count++;
    return L;
}

void display(List L){
    int x;

    for(x = 0; x < L.count; x++){
        printf("%d ", L.elemPtr[x]);
    }
    printf("\n");
}

List resize(List L){
    int newMax = L.max * 2;
    int *newPTR = (int*)realloc(L.elemPtr, sizeof(int) * newMax);

    if(newPTR != NULL){
        L.elemPtr = newPTR;
        L.max = newMax;
    } else{
        printf("you suck!");
    }
    return L;
}