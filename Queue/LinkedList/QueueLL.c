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
    Queue *init = malloc(sizeof(Queue));
    if(init != NULL){
        init->front = NULL;
        init->rear = NULL;
    }
    return init;
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
            q->front = q->rear = newNode;
        } else{
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

int dequeue(Queue* q){
    if(!isEmpty(q)){
        LLQueue temp = q->front;
        int value = temp->data;
        q->front = temp->next;
        if(q->front == NULL){
            q->rear = NULL;
        }
        free(temp);
        return value;
    }
}

int front(Queue* q){
    if(!isEmpty(q)){
        return q->front->data;
    }
}

void display(Queue* q){
    Queue *temp = initialize();
    int val;

    while(!isEmpty(q)){
        val = front(q);
        printf("%d ", val);
        dequeue(q);
        enqueue(temp, val);
    }
    while(!isEmpty(temp)){
        val = front(temp);
        dequeue(temp);
        enqueue(q, val);
    }
    printf("\n");
}