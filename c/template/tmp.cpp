#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef std::string string;

// ******* function *******
template <class T>
T min(T x, T y) {
    return x < y ? x : y;
}
// ******* function *******


// ******* class *******
template <typename T1, typename T2>
class People {

    private:
	T1 name;
	T2 id;

    public:
	People(T1 name, T2 id);
	~People();
	void show();
	void setName(T1 n);
	void setId(T2 i);

};

template <typename T1, typename T2>
People<T1, T2>::People(T1 n, T2 i):name(n), id(i) {
    std::cout << "constructor..." << std::endl;
}

template <typename T1, typename T2>
People<T1, T2>::~People() {
    std::cout << "deconstructor..." << std::endl;
}

template <typename T1, typename T2>
void People<T1, T2>::show() {
    std::cout << "name : " << name << std::endl;
    std::cout << "id : " << id << std::endl;
}

template <typename T1, typename T2>
void People<T1, T2>::setName(T1 n) {
    name = n;
}

template <typename T1, typename T2>
void People<T1, T2>::setId(T2 i) {
        id = i;
}


// ******* class *******

int main() {
    int x = 3, y = 6;
    printf("min is : %d\n", min(x, y));

    // use class for example
    People<string, int> people_first("Helon", 12);
    people_first.show();

    People<string, int> *people_second;
    people_second =  new People<string, int>("Kate", 111);
    people_second->setName("Kate");
    people_second->setId(123);
    people_second->show();

    delete people_second;

    return 0;
}
