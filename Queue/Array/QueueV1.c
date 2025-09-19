#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int count;
} List;

typedef struct{
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main(){
    Queue *test = initialize();

    enqueue(test, 3);
    enqueue(test, 2);
    display(test);

    dequeue(test);
    display(test);

    return 0;
}

Queue* initialize(){
    Queue *new = malloc(sizeof(Queue));
    if(new != NULL){
        new->list.count = 0;
        new->front = -1;
        new->rear = -1;
    }
    return new;
}

bool isEmpty(Queue* q){
    return (q->list.count == 0) ? 1 : 0;
}

bool isFull(Queue* q){
    return (q->list.count == MAX) ? 1 : 0;
}

void enqueue(Queue* q, int value){
    if(!isFull(q)){
        if(q->list.count == 0){
            q->front = 0;
            q->rear = 0;
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
        if(q->front == 1){
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

int front(Queue* q){
    if(!isEmpty(q)){
        return q->list.items[q->front];
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