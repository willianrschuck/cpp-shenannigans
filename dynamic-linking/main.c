#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);

int main(void) {
    printf("1+1=%d\n", add(1, 1));
    printf("1-1=%d\n", sub(1, 1));
    return 0;
}
