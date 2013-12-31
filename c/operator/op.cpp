#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

typedef std::string string;

// first class
class FirstName {
    private:
	string name;
	int length;
    public:
	FirstName();
	FirstName(string n);
	~FirstName();
	void setName(string n);
	string getName();
	int getLength();
};

FirstName::FirstName() {
    name = "";
    length = strlen(name.c_str());
}
FirstName::FirstName(string n) {
    name = n;
    length = strlen(name.c_str());
}

FirstName::~FirstName() {}

void FirstName::setName(string n) {
    name = n;
    length = strlen(name.c_str());
}

string FirstName::getName() {
    return name;
}

int FirstName::getLength() {
    return length;
}

// second class
class LastName {
    private:
	string name;
	int length;
    public:
	LastName();
	LastName(string n);
	~LastName();
	void setName(string n);
	string getName();
	int getLength();
};

LastName::LastName() {
    name = "";
    length = 0;
}

LastName::LastName(string n) {
    name = n;
    length = strlen(name.c_str());
}

LastName::~LastName(){}

void LastName::setName(string n) {
    name = n;
    length = strlen(name.c_str());
}

string LastName::getName() {
    return name;
}

int LastName::getLength() {
    return length;
}

static void prname(string name) {
    std::cout << " : " << name << std::endl;
}

static void prlength(int l) {
    std::cout << " l() : " << l << std::endl;
}

int main() {
    FirstName fn("Kate");
    LastName ln("Pyen");
    prname(fn.getName());
    prlength(fn.getLength());
    prname(ln.getName());
    prlength(ln.getLength());

    return 0;
}
