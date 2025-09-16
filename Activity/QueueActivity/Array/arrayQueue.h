#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

// write your functions here
Queue* initialize(){
    Queue *new = malloc(sizeof(Queue));
    if(new != NULL){
        new->front = -1;
        new->rear = -1;
        new->list.count = 0;
    }
    return new;
}

void enqueue(Queue* q, int value){
    if(q->list.count != MAX){
        if(q->list.count == 0){
            q->front++;
            q->rear++;
        } else{
            q->rear = (q->rear + 1) % MAX;
        }
        q->list.items[q->rear] = value;
        q->list.count++;
    }
}

int dequeue(Queue* q){
    if(!isEmpty(q)){
        int value = q->list.items[q->front];
        if(q->list.count == 1){
            q->front = -1;
            q->rear = -1;
            q->list.count = 0;
        } else{
            q->front = (q->front + 1) % MAX;
            q->list.count--;
        }
        return value;
    }
}

bool isFull(Queue* q){
    return (q->list.count == MAX) ? 1 : 0;
}

bool isEmpty(Queue* q){
    return (q->list.count == 0) ? 1 : 0;
}

void display(Queue* q){
    int x;

    if(q->list.count != 0){
        for(x = q->front; x <= q->rear; x++){
            printf("%d ", q->list.items[x]);
        }
        printf("\n");
    } else{
        printf("Queue is empty.\n");
    }
}