#include <stdio.h>
#include <stdbool.h>
#include "types.h"

// write your functions here

void initialize(Stack *s){
    s->top = -1;
}

bool isFull(Stack *s){
    return (s->top == MAX - 1) ? 1 : 0;
}
bool isEmpty(Stack *s){
    return (s->top == -1) ? 1 : 0;
}

void push(Stack *s, int value){
    if(s->top != MAX - 1){
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s){
    if(s->top != -1){
        int value = s->items[s->top];
        s->top--;
        return value;
    } else{
        printf("Errer: All stacks are empty. Cannot pop container.\n");
    }
}

int peek(Stack *s){
    if(s->top != - 1){
        return s->items[s->top];
    }
}

int top(Stack *s){
    return s->items[s->top];
}

void display(Stack* s){
    
    if(s->top != -1){
        int x;
        for(x = 0; x <= s->top; x++){
            printf("%d\n", s->items[x]);
        }
    } else{
        printf("Stack is empty.\n");
    }
}