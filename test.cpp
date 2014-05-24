#include <iostream>
#include <string.h>
using namespace std;

class blabla {
private:
	
public:
	blabla() {
		cout << "Ima me :D" << endl;
	}
};

void funkcija(blabla &from) {
	cout << "Funkcija: " << &from << endl;
}

int main() {
	blabla eden;
	blabla dva;
	cout << &eden << endl << &dva << endl;
	funkcija(eden);
	if (&eden == &eden) {
		cout << "Isti" << endl;
	}
	return 0;
}