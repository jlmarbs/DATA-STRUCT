#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// initVHeap
void initVHeap(VHeap *V){
    V->avail = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        V->H[i].next = i + 1;
    }
    V->H[MAX_SIZE - 1].next = -1;
}

// alloc
int alloc(VHeap *V){
    int retVal = V->avail;
    if(V->avail != -1){
        V->avail = V->H[retVal].next;
    }
    return retVal;
}

// dealloc
void dealloc(VHeap *V, int index){
    if(index >= 0 && index < MAX_SIZE){
        V->H[index].next = V->avail;
        V->avail = index;
    }
}

// insertArticle
int insertArticle(VHeap *V, int *L, Article article, int pos){
    int newCell = alloc(V);
    if(newCell != -1){
        V->H[newCell].article = article;
        V->H[newCell].next = newCell;
        int *trav = L;
        while(*trav != -1 && *trav != pos){
            trav = &(V->H[*trav].next);
        }
        V->H[newCell].next = *trav;
        *trav = newCell;
        return newCell;
    } else{
        printf("Error: Heap is full. Cannot insert new article.\n");
    }
}

// viewArticles
void viewArticles(VHeap V, int L){
    int trav;
    if(L != -1){
        printf("\n--- List of Articles ---\n");
        for(trav = L; trav != -1; trav = V.H[trav].next){
            printf("ID: %d | Title: %s\n", V.H[trav].article.id, V.H[trav].article.title);
        }   
    printf("------------------------\n\n");
    } else{
        printf("The knowledge base is empty.\n");
    }
}

// searchArticle
void searchArticle(VHeap V, int L, int id) {
    int trav;
    for (trav = L; trav != -1; trav = V.H[trav].next) {
        if (V.H[trav].article.id == id) {
            printf("\n--- Article Found ---\n");
            printf("ID: %d\n", V.H[trav].article.id);
            printf("Title: %s\n", V.H[trav].article.title);
            printf("Content: %s\n", V.H[trav].article.content);
            printf("---------------------\n\n");
        }
    }
    printf("Article with ID %d not found.\n\n", id);
}

// deleteArticle
int deleteArticle(VHeap *V, int *L, int id){
    int *trav, temp;
    trav = L;

    while(*trav != -1 && V->H[*trav].article.id != id){
        trav = &(V->H[*trav].next);
    }

    if(*trav != -1 && V->H[*trav].article.id == id){
        temp = *trav;
        *trav = V->H[*trav].next;
        dealloc(V, temp);
        printf("Article with ID %d deleted successfully.\n\n", id);
    } else{
        printf("Article with ID %d not found.\n\n", id);
    }
    return 0;
}