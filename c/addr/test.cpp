#include <iostream>
#include <string>
#include <stdio.h>


struct Object
{
    int first;
    int second;
    int third;
};


int main( int argc, char * argv[] )
{
  Object *obj = new Object;
  obj->first=123;
  obj->second=456;
  printf("object address = %p\n", obj);
  printf("first address = %p\n", &obj->first);
  Object *obj1 = (Object *)&obj->first;
  printf("second is %d\n", obj1->second);
  return 0;
}
