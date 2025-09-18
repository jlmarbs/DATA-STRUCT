#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} *LLQueue;

typedef struct {
    LLQueue front;
    LLQueue rear;
} Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main(){
    Queue *Q = initialize();

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    display(Q);

    dequeue(Q);
    display(Q);

    return 0;
}

Queue* initialize(){
    Queue *new = malloc(sizeof(Queue));
    if(new != NULL){
        new->front = NULL;
        new->rear = NULL;
    }
    return new;
}

bool isFull(Queue* q){
    return false;
}

bool isEmpty(Queue* q){
    return (q->front == NULL) ? 1 : 0;
}

void enqueue(Queue* q, int value){
    LLQueue newNode = malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->data = value;
        newNode->next = NULL;

        if(isEmpty(q)){
            q->front = newNode;
            q->rear = newNode;
        } else{
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

int dequeue(Queue* q){
    if(q->front != NULL){
        LLQueue temp;
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

int front(Queue* q){
    if(!isEmpty(q)){
        return q->front->data;
    }
}

void display(Queue* q){
    Queue *tempQueue = initialize();
    int value;

    while(!isEmpty(q)){
        value = front(q);
        printf("%d ", value);
        dequeue(q);
        enqueue(tempQueue, value);
    }

    while(!isEmpty(tempQueue)){
        value = front(tempQueue);
        dequeue(tempQueue);
        enqueue(q, value);
    }
    printf("\n");
}