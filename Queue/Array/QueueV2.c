#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize();
int isEmpty(Queue* q);
int isFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main(){

    Queue *test = initialize();

    enqueue(test, 3);
    enqueue(test, 5);
    display(test);

    dequeue(test);
    display(test);

    return 0;
}

Queue* initialize(){
    Queue *new = malloc(sizeof(Queue));
    if(new != NULL){
        new->front = 1;
        new->rear = 0;
    }
    return new;
}

int isEmpty(Queue* q){
    return (q->front == (q->rear + 1) % MAX);
}

int isFull(Queue* q){
    return (q->front == (q->rear + 2) % MAX);
}

void enqueue(Queue* q, int value){
    if(!isFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q){
    if(!isEmpty(q)){
        int elem = q->items[q->front];
        q->front = (q->front + 1) % MAX;
        return elem;
    }
}

int front(Queue* q){
    if(!isEmpty(q)){
        return q->items[q->front];
    }
}

void display(Queue* q){
    int x;

    if(!isEmpty(q)){
        for(x = q->front; x != (q->rear + 1) % MAX; x = (x + 1) % MAX){
            printf("%d\n", q->items[x]);
        }
    }
    printf("\n");
}