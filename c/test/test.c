#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int *array = NULL;

    array = (int*)malloc(5 * sizeof(int));
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    array[3] = 3;
    array[4] = 4;

    int i = 0;
    for (i; i < 5; i++) {
        printf("array[%d] : %d\n", i, array[i]);
    }

    printf("array size : %d\n", (sizeof(array) / sizeof(int)));

    int array2[5] = {0, 1, 2, 3, 4};
    printf("array2 size : %d\n", (sizeof(array2) / sizeof(int)));

    show_size(array2);

    char *s1 = "hello";
    char *s2 = "world";
    printf("_____ : %d", strcmp(s1, s1));
    return 0;

}

void show_size(int *array) {
    printf("size : %d\n", (sizeof(array) / sizeof(int)));
}
