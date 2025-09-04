#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int top;
} Stack;

Stack* initialize();
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main(){

    Stack *test = initialize();

    push(test, 3);
    push(test, 6);
    push(test, 2);
    push(test, 5);
    push(test, 1);
    display(test);

    pop(test);
    display(test);

    return 0;
}

Stack* initialize(){
    Stack *new = malloc(sizeof(Stack));
    if(new != NULL){
        new->top = MAX;
    }
    return new;
}

void push(Stack* s, int value){
    if(s->top != -1){
        s->top--;
        s->items[s->top] = value;
    }
}

int pop(Stack* s){
    if(s->top != MAX){
        int value = s->items[s->top];
        s->top++;
        return value;
    }
}

int peek(Stack* s){
    if(s->top != MAX - 1){
        return s->items[s->top];
    }
}

void display(Stack* s){
    int x;

    for(x = s->top; x <= MAX - 1; x++){
        printf("%d\n", s->items[x]);
    }
    printf("\n");
}