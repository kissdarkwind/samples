#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *src = "Hello";
    char *src2 = "World!";
    char *dest = malloc(128);
    dest = strcat(dest, src);
    dest = strcat(dest, src2);
    dest = strcat(dest, "\n");

    printf("dest : %s", dest);

    size_t len = strlen(dest);
    printf("len : %d\n", len);

    free(dest);
    return 0;
}
