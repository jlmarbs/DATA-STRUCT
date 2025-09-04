#include <stdio.h>
#include <stdlib.h>
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
    if(q->list.count != 0){
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

int front(Queue* q){
    if(q->list.count != 0){
        return q->list.items[q->front];
    }
}

void display(Queue* q){
    int x;

    if(q->list.count != 0){
        for(x = q->front; x <= q->rear; x++){
            printf("%d\n", q->list.items[x]);
        }
        printf("\n");
    }
}