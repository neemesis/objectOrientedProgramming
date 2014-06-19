#include <iostream>
#include <string.h>
using namespace std;

class A {
private:
	int a;
public:
	void postaviA(int a) {this -> a = a;}
	void pechatiA() {cout << a << endl;}
	A operator +(int b) {
		a += b;
		return *this;
	}
	int getA() {return a;}
};

class B {
private:
	int b;
public:
	void postaviB(int b) {this -> b = b;}
	void pechatiB() {cout << b << endl;}
	B operator +(A &from) {
		b += from.getA();
		return *this;
	}
};

int main() {
	A a;
	B b;
	a.postaviA(10);
	b.postaviB(22);
	a.pechatiA();
	b.pechatiB();
	a = a + 4;
	a.pechatiA();
	b = b + a;
	b.pechatiB();
	return 0;
}