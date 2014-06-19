#include <iostream>
#include <string.h>
using namespace std;

class Krug {
protected:
	float radius;
	static const float pi = 3.1415;
public:
	Krug(float radius = 0) {this -> radius = radius;}
	float area() {return pi * radius * radius;}
	float length() {return 2 * radius * pi;}
	bool check() {return area() == length();}
};

int main() {
	float r;
	cin >> r;
	Krug k(r);
	cout << k.length() << endl;
	cout << k.area() << endl;
	cout << k.check() <<endl;
	return 0;
}