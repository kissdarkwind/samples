#include <create.h>

Hello::Hello() {
    printf("___init___\n");
}

void Hello::add(int a, int b) {
    printf("result -> %d\n", a + b);
}

int Hello::run() {

    add();
    return 0;

}
