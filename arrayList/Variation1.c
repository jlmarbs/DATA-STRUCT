#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int position);
List insertSorted(List L, int data);
void displayList(List L);

int main(){
    List myList;
    List mySortedList;
    myList = initialize(myList);
    mySortedList = initialize(mySortedList);

    myList = insertPos(myList, 3, 0);
    myList = insertPos(myList, 2, 1);
    myList = insertPos(myList, 1, 2);
    myList = insertPos(myList, 4, 2);
    displayList(myList);

    myList = deletePos(myList, 0);
    displayList(myList);

    locate(myList, 1);

    mySortedList = insertSorted(mySortedList, 3);
    mySortedList = insertSorted(mySortedList, 1);
    mySortedList = insertSorted(mySortedList, 8);
    mySortedList = insertSorted(mySortedList, 5);
    displayList(mySortedList);

    return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position >= 0 && position <= L.count){
        if(L.count < MAX){
            int x;
            for(x = L.count; x > position; x--){
                L.elem[x] = L.elem[x - 1];
            }
            L.elem[position] = data;
            L.count++;
        }
    }
    return L;
}

List deletePos(List L, int position){
    if(position >= 0 && position <= L.count){
        if(L.count > 0){
            int x;
            for(x = position; x < L.count; x++){
                L.elem[x] = L.elem[x + 1];
            }
            L.count--;
        }
    }
    return L;
}

int locate(List L, int position){
    int x;
    for(x = 0; x < L.count; x++){
        if(L.elem[x] == position){
            return L.elem[x];
        } else{
            return -1;
        }
    }
}

List insertSorted(List L, int data){
    int x, pos;
    if(L.count < MAX){
        for(pos = 0; pos < L.count; pos++){
            if(L.elem[pos] >= data){
                break;
            }
        }
        for(x = L.count; x > pos; x--){
            L.elem[x] = L.elem[x - 1];
        }
        L.elem[pos] = data;
        L.count++;
    }
    return L;
}

void displayList(List L){
    int x;

    for(x = 0; x < L.count; x++){
        printf("%d ", L.elem[x]);
    }
    printf("\n");
}