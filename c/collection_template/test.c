#include "col.h"

int main() {
        Collection<char> c;
        c.add("Hello");
        printf("content : %s\n", c.item(0));

        c.add("World");
        c.add("Kate");
        c.add("Join");
        c.add("HUHU");

        c.remove(2);
        printf("________________\n");
        printf("content : %s\n", c.item(0));
        printf("content : %s\n", c.item(1));
        printf("content : %s\n", c.item(2));
        printf("content : %s\n", c.item(3));
        printf("________________\n");

        Collection<A> cc;
        A a;
        a.name = "Opps";
        cc.add(&a);
        printf("a name : %s\n", (cc.item(0))->name);

        Collection<char> *ccc = new Collection<char>;
        ccc->add("Hello");
        printf("___### : %s\n", ccc->item(0));
        delete ccc;

        return 0;
}

