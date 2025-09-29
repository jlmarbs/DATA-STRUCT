#include <stdio.h>

int divideByPowerOfTwo(int num, int power) {
    // Your code here
    int result = num >> power;

    return result;
}

int main() {
    printf("100 divided by 8 is: %d\n", divideByPowerOfTwo(100, 3));
    printf("-100 divided by 8 is: %d\n", divideByPowerOfTwo(-100, 3));

    return 0;
}
