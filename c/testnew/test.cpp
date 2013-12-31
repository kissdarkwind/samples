#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class A {

public:
    A();
    ~A();

    char* getName();

};

A::A() {}
A::~A() {}

char* A::getName() {
    return "Name";
}

A* getA() {
    A *a = new A;
    return a;
}

int main() {

    A *a = getA();
    printf("a addr : %p\n", a);
    printf("a getName : %s\n", a->getName());

    delete a;
    // the value can still be output, because the memory doesn't be assigned to another, and never do memset(*, 0, *).
    printf("a addr2 : %p\n", a);
    printf("a getName2 : %s\n", a->getName());

    // will throw exception
    delete a;
    printf("a addr2 : %p\n", a);
    return 0;

}
