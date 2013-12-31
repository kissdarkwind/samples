#include <stdio.h>

class Hello {
public:
    static const int SIZE = 10;
};

int main() {
    printf("str1 : %d\n", Hello::SIZE);
    return 0;
}
