#include <stdio.h>

void foo(int *p) {
    *p = *p + 1; // acessa variavel via ponteiro
}

int main(void) {
    int a = 0;
    int b;    
    while (1) {
        foo(&a);
        
        if (a > 5) {
            b = 1;
            printf("a=%d, b=%d\n", a, b);
        }
    }
    return 0;
}
