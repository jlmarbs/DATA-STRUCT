#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
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

    push(test, 10);
    push(test, 20);
    push(test, 30);
    display(test);
    printf("Current top: %d\n\n", peek(test));

    pop(test);
    display(test);
    printf("Current top: %d\n\n", peek(test));

    return 0;
}

Stack* initialize(){
    Stack *new = malloc(sizeof(Stack));
    if(new != NULL){
        new->top = NULL;
    }
    return new;
}

bool isFull(Stack* s){
    return false;
}

bool isEmpty(Stack* s){
    return (s->top == NULL) ? 1 : 0;
}

void push(Stack* s, int value){
    Node *newNode = malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = value;
        newNode->next = s->top;
        s->top = newNode;
    }
}

int pop(Stack* s){
    if(!isEmpty(s)){
        Node *temp = s->top;
        int value = temp->data;
        s->top = s->top->next;
        free(temp);
        return value;
    }
}

int peek(Stack* s){
    if(!isEmpty(s)){
        return s->top->data;
    }
}

void display(Stack* s){
    if(!isEmpty(s)){
        Node *trav;
        for(trav = s->top; trav != NULL; trav = trav->next){
            printf("%d\n", trav->data);
        }
    }
    printf("\n");
}