#include <stdio.h>

int main() {

    int value1 = 1;
    int *pi = &value1;
    void *pv = &value1;

    int *pi2 = (int*)pv;
    printf("pi : %p   pi-value: %d\n", pi, *pi);
    printf("pi2: %p   pi2-value:%d\n", pi2, *pi2);

    size_t pi_size = sizeof(pi);
    size_t pv_size = sizeof(pv);

    printf("pi_size : %d\n", pi_size);
    printf("pv_size : %d\n", pv_size);

    return 0;

}
