#include <stdio.h>


class A {

public:
    A();
    ~A();
    char* getName();
    void setName(char* n);

private:
    char* name;

};

A::A() {}
A::~A() {}

char* A::getName() {
    return name;
}

void A::setName(char* n) {
    name = n;
}

void printMessage(A& a) {
    char* n = a.getName();
    printf("A name : %s\n", n);
}

int main() {

    A a;
    a.setName("Honey");
    printMessage(a);
    return 0;

}
