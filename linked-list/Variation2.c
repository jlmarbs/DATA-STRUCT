#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct{
    Node *head;
    int count;
} List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main(){

    List *L = initialize();

    insertFirst(L, 3);
    insertFirst(L, 4);
    display(L);

    insertLast(L, 7);
    display(L);

    deleteStart(L);
    display(L);

    insertPos(L, 5, 2);
    display(L);

    deleteLast(L);
    display(L);

    // empty(L);
    // display(L);

    deletePos(L, 1);
    display(L);

    return 0;
}

List* initialize(){
    List *ptr = malloc(sizeof(List));

    if(ptr != NULL){
        ptr->head = NULL;
        ptr->count = 0;
    }
    return ptr;
}

void empty(List *list){
    Node *current;
    Node *temp;

    for(current = list->head; current != NULL; current = temp){
        temp = current->next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node *newNode = malloc(sizeof(struct node));

    if(newNode != NULL){
        newNode->data = data;
        newNode->next = list->head;
        list->head = newNode;
        list->count++;
    }
}

void insertLast(List *list, int data){
    Node *current;

    Node *newNode = malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->data = data;
        newNode->next = NULL;

        if(list->head == NULL){
            list->head = newNode;
        } else{
            for(current = list->head; current->next != NULL; current = current->next){}
            current->next = newNode;
        }
        list->count++;
    } 
}

void insertPos(List *list, int data, int index){
    if(index >= 0 && index <= list->count){
        if(index == 0){
            insertFirst(list, data);
        } else if(index == list->count){
            insertLast(list, data);
        } else{
            Node *newNode = malloc(sizeof(struct node));
            if(newNode != NULL){
                newNode->data = data;

                int x;
                Node *current = list->head;
                for(x = 0; x < index - 1; x++){
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                list->count++;
            }
        }
    }
}

void deleteStart(List *list){
    Node *current;

    current = list->head;
    list->head = current->next;
    free(current);
    list->count--;
}

void deleteLast(List *list){
    if(list->count == 1){
        free(list->head);
        list->head = NULL;
        list->count--;
    } else{
        Node *current = list->head;
        int x;

        for(x = 0; x < list->count - 2; x++){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        list->count--;
    }
}

void deletePos(List *list, int index){
    if(index >= 0 && index <= list->count){
        if(index == 0){
            deleteStart(list);
        } else{
            Node *current = list->head;
            int x;

            for(x = 0; x < index - 1; x++){
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            list->count--;
        }
    }
}

int retrieve(List *list, int index){
    if(index >= 0 && index < list->count){
        Node *current = list->head;
        int x;

        for(x = 0; x < list->count; x++){
            current = current->next;
        }
        return current->data;
    }
    return -1;
}

int locate(List *list, int data){
    if(list->head == NULL){
        return -1;
    } else{
        Node *current;
        int index = 0;

        for(current = list->head; current != NULL; current = current->next){
            if(current->data == data){
                return index;
            }
            index++;
        }
        return -1;
    }
}

void display(List *list){
    Node *current;
    int x;
    printf("head: ");
    for(current = list->head; current != NULL; current = current->next){
        printf("%d -> ", current->data);
    }
    printf("\ncount: %d\n", list->count);
}