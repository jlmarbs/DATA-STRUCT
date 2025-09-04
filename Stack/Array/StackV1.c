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
    push(test, 1);
    // pop(test);
    display(test);

    return 0;
}

Stack* initialize(){
    Stack *new = malloc(sizeof(Stack));
    if(new != NULL){
        new->top = -1;
    }
    return new;
}

void push(Stack* s, int value){
    if(s->top != MAX - 1){
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack* s){
    if(s->top != -1){
        int value = s->items[s->top];
        s->top--;
        return value;
    }
}

int peek(Stack* s){
    if(s->top != -1){
        return s->items[s->top];
    }
}

// void display(Stack* s){
//     while(s->top != -1){
//         printf("%d ", pop(s));
//     }
//     printf("\n");
// }

void display(Stack* s){
    int x;

    for(x = s->top; x >= 0; x--){
        printf("%d\n", s->items[x]);
    }
}