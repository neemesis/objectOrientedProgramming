#include <iostream>
#include <string.h>
using namespace std;

void pechatiStatic(int a) {a += 9; cout << a << endl;}

int main() {
	static int a = 9;
	pechatiStatic(a);
	return 0;
}