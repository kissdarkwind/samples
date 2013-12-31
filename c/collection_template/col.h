#include <stdio.h>
#include <stdlib.h>

#include <vector>

template <typename T> class Collection {

public:
        T* item(int index);
        int getLength();
        void add(T *t);
        void remove(int index);

protected:
        std::vector<T*> v;

};

class A {
public:
        char *name;
};
