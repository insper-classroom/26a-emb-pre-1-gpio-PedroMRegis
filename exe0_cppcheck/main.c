#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTS 5

int multiplyNumbers(int x, int y) {
    int product = x * y;
    return product;
}

int main(void) {
    int a = 10;
    int b = 5;
    int result = multiplyNumbers(a, b);
    printf("Result: %d\n", result);

    int arr[NUM_ELEMENTS];
    for(int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
