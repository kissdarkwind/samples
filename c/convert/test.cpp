#include "stdio.h"
#include "stdlib.h"
#include "string.h"

class A {
public:
    A();
    ~A();
};

A::A() {}
A::~A() {}

typedef struct _ST {
    A* a;
    void *b;
} ST;

int main() {

    ST s = {NULL, NULL};
    A *a = new A;
    s.a = a;
    s.b = (void*)("Hello");
    printf("str : %s\n", s.b);

    printf("s addr : %p\n", &s);
    printf("1st prop addr : %p\n", &(s.a));

    ST s2 = *((ST*)(&(s.a)));
    printf("s2 str : %s\n", s2.b);

}
