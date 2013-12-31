#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Common {
private:
    char *name;
    int id;

public:
    Common(char *_name, int _id);
    ~Common();
    char* getName();
};
