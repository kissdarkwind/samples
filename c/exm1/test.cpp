#include <stdio.h>
#include <stdlib.h>

class A
{
public:
	void add(int a = 1, int b = 1)
	{
		printf("result : %d\n", a + b);
	}

        void run() {
            add();
        }
};

int main()
{
	A obj;
	obj.run();
        return 0;
}
