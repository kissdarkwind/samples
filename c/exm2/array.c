#include <stdio.h>
#include <stdlib.h>

void change(int *value) {
    *value = 3;
}

int a = 5;
int *getSth() {
    a += 1;
    return &a;
}

main () {

    int array[2][2] = {
        {1, 10},
        {100, 1000}
    };

    int (*arp)[2][2];
    arp = &array;
    printf("content : %d\n", (*arp)[0][0]);
    printf("content : %d\n", (*(**arp + 1)));
    printf("content : %d\n", (*(**arp + 2)));
    printf("---------------\n");
    // *array = array[0] = &array[0]
    printf("*array : %p    array[0] : %p   &array[0] : %p\n", *array, array[0], &array[0]);
    // **array = *array[0] = *array[0] = array[0][0]
    printf("**array : %d    *array[0] : %d   array[0] : %d\n", **array, *array[0], *array[0]);
    // arp = &array
    // *arp -> array[0]
    // **arp -> array[0][0]
    // *** arp = print array[0][0]
    printf("*((**arp) + 1)) :  %d\n", *((**arp) + 1));
    printf("*((**arp) + 2)) :  %d\n", *((**arp) + 2));
    printf("*((**arp) + 3)) :  %d\n", *((**arp) + 3));

    printf("---------------\n");
    int arr[2] = {1, 5};
    int (*arr_p)[2];
    arr_p = &arr;
    printf("arr_p : %p   &arr : %p   *arr_p : %p\n", arr_p, arr, *arr_p);
    // *arr = arr[0]
    // &arr == arr == &arr[0]
    // *arr_p == arr[0] == *arr

    int num = 1;
    change(&num);
    printf("num : %d\n", num);

    char *cs[] = {
        "hello",
        "world"
    };

    printf("char conteng : %s\n", cs[0]);

    char *(*char_arp)[];
    char_arp = &cs;
    printf("char * array content : %s\n", (*char_arp)[0]);

    int *(*func)(int) = getSth;
    printf("________ getSth : %d\n", *func(a));

}