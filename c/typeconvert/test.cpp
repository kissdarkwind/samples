#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class A {};
class B {};
class C {};

int main() {

    A *a = new A;
    B *b = new B;
    C *c = new C;

    B *cb = static_cast<B*>(b);
    printf("cb converted...\n");

    void *v = b;
    C *cc = static_cast<C*>(v);
    printf("cc converted...\n");

    C *ccc = (C*)(v);
    printf("ccc converted...\n");

    return 0;

}
