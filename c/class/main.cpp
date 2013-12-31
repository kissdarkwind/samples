#include "main.h"
#include "other.h"

Common::Common(char *_name, int _id) {
    name = _name;
    id = _id; 
}

Common::~Common(){}

char* Common::getName() {
    return name;
}

int main() {

    Common c("Kate", 12);
    printf("name : %s\n", c.getName());

    Other o(1001);
    printf("key : %d\n", o.getKey());

    return 0;
}
