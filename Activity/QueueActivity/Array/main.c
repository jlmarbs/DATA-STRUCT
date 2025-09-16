#include <stdio.h>
#include <stdlib.h>
#include "arrayQueue.h"
#include "types.h"

int main() {
    // write your code here
    Queue *reg = initialize();
    Queue *prio = initialize();

    int choice;
    int running = 1;
    int nextNumber = 1;

    while(running){
        printf("--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n");
        printf("2. Enter Priority Queue\n");
        printf("3. Call Next Customer\n");
        printf("4. Display Queues\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(!isFull(reg)){
                    enqueue(reg, nextNumber);
                    printf("You have entered the Regular queue. Your number is %d.\n\n", nextNumber);
                    nextNumber++;
                    break;
                } else{
                    printf("Regular queue is full. Please try again later.\n\n");
                }
                break;

            case 2:
                if(!isFull(prio)){
                    enqueue(prio, nextNumber);
                    printf("You have entered the Priority queue. Your number is %d.\n\n", nextNumber);
                    nextNumber++;
                    break;
                } else{
                    printf("Priority queue is full. Please try again later.\n\n");
                }
                break;

            case 3:
                if(!isEmpty(prio)){
                    printf("Calling next customer from Priority Queue. Customer number: %d\n\n", dequeue(prio));
                } else if(!isEmpty(reg)){
                    printf("Calling next customer from Regular Queue. Customer number: %d\n\n", dequeue(reg));
                } else{
                    printf("The Queue is empty.\n");
                }
                break;

            case 4:
                printf("\n-- Current Queue Status --\n");
                printf("Regular Queue: ");
                display(reg);
                printf("Priority Queue: ");
                display(prio);
                printf("\n");
                break;

            case 5:
                running = 0;
                printf("Exiting program. Goodbye!\n");
        }
    }
    
    return 0;
}