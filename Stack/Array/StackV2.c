#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
    int top;
} Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
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
        new->top = MAX - 1;
    }
    return new;
}

bool isFull(Stack* s){
    return (s->top == -1) ? 1 : 0;
}

bool isEmpty(Stack* s){
    return (s->top == MAX - 1) ? 1 : 0;
}

void push(Stack* s, int value){
    if(!isFull(s)){
        s->top--;
        s->items[s->top] = value;
    }
}

int pop(Stack* s){
    if(!isEmpty(s)){
        int value = s->items[s->top];
        s->top++;
        return value;
    }
}

int peek(Stack* s){
    if(!isEmpty(s)){
        return s->items[s->top];
    }
}

void display(Stack* s){
    Stack *temp = initialize();
    int val;
    
    while(!isEmpty(s)){
        val = peek(s);
        printf("%d\n", val);
        pop(s);
        push(temp, val);
    }
    
    while(!isEmpty(temp)){
        val = peek(temp);
        pop(temp);
        push(s, val);
    }
    printf("\n");
}