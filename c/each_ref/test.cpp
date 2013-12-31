#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _STR {
    void *content;
} STR;

class Clz {

public:
    Clz();
    ~Clz();
    STR* getSTR();

    STR *s;

};

typedef struct _Data {
    STR *s;
    void *clz;
} Data;

Clz::Clz(): s(NULL) {}
Clz::~Clz() {}

STR* Clz::getSTR() {
    s = (STR*)malloc(sizeof(STR));
    s->content = this;
    return s;
}

int main() {

    Data *d = (Data*)malloc(sizeof(Data));
    Clz *c = new Clz;
    d->s = c->getSTR();
    d->clz = c;

    printf("d : %p\n", d);
    printf("d->s : %p\n", d->s);
    printf("d->clz : %p\n", d->clz);
    printf("c : %p\n", c);
    printf("c->s : %p\n", c->s);

    return 0;
}
