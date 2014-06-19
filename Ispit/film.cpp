#include <iostream>
#include <string.h>
using namespace std;

class Film {
private:
	char ime[100];
	char reziser[50];
	char zanr[50];
	int godina;
public:
	Film(char ime[], char reziser[], char zanr[], int godina);
	int getYear() {return godina;}
	friend ostream &operator <<(ostream &out, Film &from);
};

ostream &operator <<(ostream &out, Film &from) {
	out << "Ime: " << from.ime << endl << "Reziser: " << from.reziser << endl << "Zanr: " << from.zanr << endl << "Godina" << from.godina << endl;
	return out;
}

Film::Film(char ime[] = "", char reziser[] = "", char zanr[] = "", int godina = 0) {
	strcpy(this -> ime, ime);
	strcpy(this -> reziser, reziser);
	strcpy(this -> zanr, zanr);
	this -> godina = godina;
}

void printByYear(Film *f, int n, int godina) {
	for (int i = 0; i < n; ++i) {
		if (f[i].getYear() == godina)
			cout << f[i];
	}
}

int main() {
 	int n;
 	cin >> n;
 	Film f[n];
 	for(int i = 0; i < n; ++i) {
 		char ime[100];
 		char reziser[50];
 		char zanr[50];
 		int godina;
 		cin >> ime;
 		cin >> reziser;
 		cin >> zanr;
 		cin >> godina;
 		f[i] = Film(ime, reziser, zanr, godina);
 	}
 	int godina;
 	cin >> godina;
 	
	printByYear(f, n, godina);
    
 	return 0;
 }