#include <stdio.h>

int a = 0; // var global
int b = 0; // var global

void foo(int *p) {
    *p = *p + 1; // acessa variavel via ponteiro
}

int main(void) {
    while (1) {
        foo(&a);
        
        if (a > 5) {
            b = 1;
            printf("a=%d, b=%d\n", a, b);
        }
    }
    return 0;
}
