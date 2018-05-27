#ifndef TEST_H
#define TEST_H

using namespace std;

class Test {
private:

public:
	Test(); // deafult
	Test(int); // ctor
	~Test(); // dtor
	
	void set(int);
	int testInt;
};

#endif