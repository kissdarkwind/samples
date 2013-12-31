#include "stdio.h"
#include "stdlib.h"

int main() {
    const char* strings[] = {
        "hello", "world", "!", "something else"
    };

    int size = sizeof(strings) / sizeof(char*);
    printf("size is :%d\n", size);
    return 0;
}
