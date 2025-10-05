#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// Write your functions here...
int hashFunction(int rgb[3]){
    return (rgb[0] * 3 + rgb[1] * 5 + rgb[2] * 7) % PALETTE_SIZE;
}

void createDictionary(Dictionary *dict){
    int x;
    for(x = 0; x < PALETTE_SIZE; x++){
        dict->buckets[x] = NULL;
    }
}

Node* createNode(Color newColor){
    Node *newNode = (Node*)malloc(sizeof(struct Node));
    if(newNode != NULL){
        strcpy(newNode->data.colorName, newColor.colorName);
        newNode->data.RGBVal[0] = newColor.RGBVal[0];
        newNode->data.RGBVal[1] = newColor.RGBVal[1];
        newNode->data.RGBVal[2] = newColor.RGBVal[2];
        newNode->next = NULL;
    }
    return newNode;
}

void insertColor(Dictionary *dict, Color newColor){
    int index = hashFunction(newColor.RGBVal);
    Node *newNode = createNode(newColor);
    if(newNode != NULL){
        newNode->next = dict->buckets[index];
        dict->buckets[index] = newNode;
        printf("-> Inserted '%s' (RGB: %d, %d, %d) into bucket [%d].\n", newColor.colorName, newColor.RGBVal[0], newColor.RGBVal[1], newColor.RGBVal[2], index);
    }
}

Color* searchColor(Dictionary *dict, int rgb[3]){
    int index = hashFunction(rgb);
    printf("Searching for RGB (%d, %d, %d) in bucket [%d]...\n", rgb[0], rgb[1], rgb[2], index);
    Node *current = dict->buckets[index];
    if(current != NULL){
        if(current->data.RGBVal[0] == rgb[0] && current->data.RGBVal[1] == rgb[1] && current->data.RGBVal[2] == rgb[2]){
            return &(current)->data;
        }
        current = current->next;
    }
}