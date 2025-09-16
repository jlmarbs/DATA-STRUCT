#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arrayStack.h"

int main() {
    // write your code here
    Stack s[3];
    int x;
    for(x = 0; x < 3; x++){
        initialize(&s[x]);
    }
    
    int choice;
    int running = 1;
    
    while(running){
        printf("--- Warehouse Inventory Management System ---\n");
        printf("1. Push a container\n");
        printf("2. Pop a container\n");
        printf("3. Check if a container exists\n");
        printf("4. Display all stacks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            int num;
            int x1;
            int pushed = 0;
            printf("Enter container ID to push: ");
            scanf("%d", &num);

            for(x1 = 0; x1 < 3; x1++){
                if(!isFull(&s[x1])){
                    push(&s[x1], num);
                    pushed = 1;
                    break;
                }
            }

            if(pushed){
                printf("Container %d pushed successfully.\n\n", num);
            }
            break;
        
        case 2:
            int popped = 0;
            int x2;

            for(x2 = 3 - 1; x2 >= 0; x2--){
                if(!isEmpty(&s[x2])){
                    printf("Container %d popped successfully.\n\n", pop(&s[x2]));
                    popped = 1;
                    break;
                }
            }

            if(!popped){
                printf("Error: All stacks are empty. Cannot pop container.\n\n");
            }
            break;
            
        case 3:
            int check;
            int found = 0;
            int x3, y;
            printf("Enter container ID to check: ");
            scanf("%d", &check);

            for(x3 = 0; x3 < 3 && !found; x3++){
                Stack copy = s[x3];
                while(!isEmpty(&copy)){
                    if(pop(&copy) == check){
                        found = 1;
                        break;
                    }
                }
            }
            
            if(found){
                printf("Container %d exists in a stack.\n\n", check);
            } else{
                printf("Container %d does not exist in any stack.\n\n");
            }
            break;
            
        case 4:
            int x4;

            for(x4 = 0; x4 < 3; x4++){
                printf("\n--- Stack %d ---\n", x4 + 1);
                display(&s[x4]);
            }
            printf("\n");
            break;
        
        case 5:
            running = 0;
            printf("Exiting program.\n");
        }
    }
    return 0;
}