#include <iostream>
#include <string.h>
using namespace std;

class Koncert {
private:
	double cena;
	char mesto[20];
	char grupa[30];
	int brojNaChlenovi;
public:
	Koncert(double cena, const char mesto[], const char grupa[], int brojNaChlenovi);
	double getCena() {return cena;}
	void setCena(double cena) {this -> cena = cena;}
	friend ostream &operator <<(ostream &out, Koncert &from);
	Koncert &operator =(Koncert *from);
};

Koncert &Koncert::operator =(Koncert *from) {
	this -> cena = from -> cena;
	this -> brojNaChlenovi = from -> brojNaChlenovi;
	strcpy(this -> mesto, from -> mesto);
	strcpy(this -> grupa, from -> grupa);
	return *this;
}

ostream &operator <<(ostream &out, Koncert &from) {
	out << "Grupa: " << from.grupa << endl;
	out << "Chlenovi: " << from.brojNaChlenovi << endl;
	out << "Mesto: " << from.mesto << endl;
	out << "Cena: " << from.cena << endl;
	return out;
}

Koncert::Koncert(double cena = 0, const char mesto[] = "", const char grupa[] = "", int brojNaChlenovi = 0) {
	this -> cena = cena;
	this -> brojNaChlenovi = brojNaChlenovi;
	strcpy(this -> mesto, mesto);
	strcpy(this -> grupa, grupa);
}

class Turneja {
private:
	Koncert *koncerti;
	int brojNaKoncerti;
public:
	Turneja();
	Turneja &operator +=(const Koncert &from);
	Turneja mojaTurneja(double maxCena);
	friend ostream &operator <<(ostream &out, Turneja &from);
};

ostream &operator <<(ostream &out, Turneja &from) {
	out << "__Turneja__" << endl;
	for (int i = 0; i < from.brojNaKoncerti; ++i) {
		out << from.koncerti[i] << endl;
	}
	return out;
}

Turneja Turneja::mojaTurneja(double maxCena) {
	Turneja tmp;
	for (int i = 0; i < brojNaKoncerti; ++i) {
		if (koncerti[i].getCena() < maxCena) {
			tmp += koncerti[i];
		}
	}
	return tmp;
}

Turneja &Turneja::operator +=(const Koncert &from) {
	if (!brojNaKoncerti) koncerti = new Koncert[1];
	Koncert *tmp = new Koncert[brojNaKoncerti + 1];
	for (int i = 0; i < brojNaKoncerti; ++i) {
		tmp[i] = koncerti[i];
	}
	tmp[brojNaKoncerti++] = from;
	delete [] koncerti;
	koncerti = tmp;
	return *this;
}



Turneja::Turneja() {
	this -> brojNaKoncerti = 0;
}

int main() {
	Koncert kon[3];
	kon[0] = new Koncert(150, "Skopje", "Pepermint", 5);
	kon[1] = new Koncert(100, "Kumanovo", "Area", 2);
	kon[2] = new Koncert(500, "Prilep", "One", 3);
	Turneja myturneja;
	myturneja += kon[0];
	myturneja += kon[1];
	myturneja += kon[2];
	cout << myturneja << endl;

	Turneja tmp = myturneja.mojaTurneja(120);
	cout << tmp << endl;
	return 0;
}