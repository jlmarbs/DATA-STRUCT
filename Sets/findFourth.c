#include <stdio.h>

int findFourth(char val){
    return (val >> 3) & 1;   
}

// void displayBit(char val){
//     int x;
//     for(x = 7; x >= 0; x--){
//         printf("%d", (val >> x) & 1);
//     }
//     printf("\n");
// }

void displayBit(char val){
    int bits = sizeof(char) * 8;
    unsigned int mask = 1 << (bits - 1);

    while(mask != 0){
        printf("%d", (val & mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}

int main(){

    printf("%d\n", findFourth(24));
    displayBit(192);
    return 0;
}