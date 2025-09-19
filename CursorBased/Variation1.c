#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap* V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void insertSorted(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);
void deleteAllOccurrence(int* L, VHeap* V, int elem);
void display(int L, VHeap V);

int main(){

    List L = -1;
    VHeap test;
    initialize(&test);

    insertSorted(&L, &test, 10);
    insertSorted(&L, &test, 70);
    insertSorted(&L, &test, 30);
    display(L, test);

    delete(&L, &test, 30);
    display(L, test);

    return 0;
}

void initialize(VHeap *V){
    V->avail = 0;
    int x;

    for(x = 0; x < MAX; x++){
        V->H[x].next = x + 1;
    }
    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap* V){
    int retVal = V->avail;

    if(V->avail != -1){
        V->avail = V->H[retVal].next;
    }
    return retVal;
}

void deallocSpace(VHeap* V, int index){
    if(index >= 0 && index < MAX){
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

void insertLast(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    int *trav = L;
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;

        while(*trav != -1){
            trav = &(V->H[newCell].next);
        }
        *trav = newCell;
    }
}

void insertSorted(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        
        if(*L == -1 || elem < V->H[*L].elem){
            V->H[newCell].next = *L;
            *L = newCell;
        } else{
            int prev = *L;
            while(V->H[prev].next != -1 && V->H[V->H[prev].next].elem < elem){
                prev = V->H[prev].next;
            }
            V->H[newCell].next = V->H[prev].next;
            V->H[prev].next = newCell;
        }
    }
}

void delete(int* L, VHeap* V, int elem){
    int *trav, temp;
    trav = L;

    while(*trav != -1 && V->H[*trav].elem != elem){
        trav = &(V->H[*trav].next);
    }

    if(*trav != -1){
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    }

}

void deleteAllOccurrence(int* L, VHeap* V, int elem){

}

void display(int L, VHeap V){
    int x;

    for(x = L; x != -1; x = V.H[x].next){
        printf("%d ", V.H[x].elem);
    }
    printf("\n");
}