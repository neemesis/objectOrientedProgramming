#include <iostream>
#include <string.h>
using namespace std;

class Letuvanje {
protected:
	char *destinacija;
	int denovi;
	double osnovnaCena;
	char tip[10];
public:
	Letuvanje(const char *dest, int day, double cena, const char type[]);
	virtual double cena() = 0;
	char *getDestinacija() {return destinacija;}
	int getDenovi() {return denovi;}
	double getOsnovnaCena() {return osnovnaCena;}
	char *getTip() {return tip;}
	double getCena() {return osnovnaCena;}
};

Letuvanje::Letuvanje(const char *dest = "", int day = 0, double cena = 0, const char type[] = "") {
	destinacija = new char[strlen(dest)];
	strcpy(destinacija, dest);
	denovi = day;
	osnovnaCena = cena;
	strcpy(tip, type);
}

class Poln_pansion : public Letuvanje {
private:
	double procent;
	double popust;
	char *listaNaJadenja;
public:
	Poln_pansion(const char *dest, int day, double cena, const char *type, double proc, double popust, const char *lista);
	double cena();
	friend ostream &operator <<(ostream &out, Poln_pansion &from);
};

ostream &operator <<(ostream &out, Poln_pansion &from) {
	out << "Destinacija: " << from.getDestinacija() << endl;
	out << "Denovi: " << from.getDenovi() << endl;
	out << "Tip: " << from.tip << endl;
	out << "Procent: " << from.procent << endl;
	out << "Popust: " << from.popust << endl;
	out << "Lista na jadenja: " << from.listaNaJadenja << endl;
	return out;
}

Poln_pansion::Poln_pansion(const char *dest = "", int day = 0, double cena = 0, const char *type = "", double proc = 0, double popust = 0, const char *lista = "") : Letuvanje(dest, day, cena, type) {
	procent = proc;
	this -> popust = popust;
	listaNaJadenja = new char[strlen(lista)];
	strcpy(listaNaJadenja, lista);
}

double Poln_pansion::cena() {
	return (1 + procent - popust) * getCena();
}

class turistichka_agencija {
private:
	int broj;
	Letuvanje **letuvanja;
public:
	turistichka_agencija(Letuvanje **let, int br);
	Letuvanje &najevtino();
	friend ostream &operator <<(ostream &out, turistichka_agencija &from);
};

ostream &operator <<(ostream &out, turistichka_agencija &from) {
	for (int i = 0; i < from.broj; ++i) {
		out << &from.letuvanja[i] << endl;
	}
	return out;
}

Letuvanje &turistichka_agencija::najevtino() {
	int min = 99999, minI = 9999;
	for (int i = 0; i < broj; ++i) {
		if (letuvanja[i] -> cena() < min) {
			min = letuvanja[i] -> cena();
			minI = i;
		}
	}
	return *letuvanja[minI];
}

turistichka_agencija::turistichka_agencija(Letuvanje **let, int br) {
	letuvanja = new Letuvanje *[br];
	broj = br;
	for (int i = 0; i < br; ++i) {
		letuvanja[i] = let[i];
	}
}

int main() {
	Letuvanje **poln = new Letuvanje *[6];
	poln[0] = new Poln_pansion("Majorka", 5, 260, "avion", 0.1, 0.01, "meso_salata");
	poln[1] = new Poln_pansion("Skopje", 5, 260, "avion", 0.1, 0.01, "meso_salata");
	poln[2] = new Poln_pansion("Pariz", 5, 260, "avion", 0.6, 0.01, "meso_salata");
	poln[3] = new Poln_pansion("London", 6, 260, "sopstven", 0.1, 0.1, "meso_salata");
	poln[4] = new Poln_pansion("Ibiza", 7, 260, "avion", 0.1, 0.2, "meso_salata");
	cout << poln[0] -> cena() << endl;
	cout << poln[1] -> cena() << endl;
	cout << poln[2] -> cena() << endl;
	cout << poln[3] -> cena() << endl;
	cout << poln[4] -> cena() << endl;
	turistichka_agencija bla(poln, 5);
	cout << bla << endl;
	cout << bla.najevtino() << endl;
	return 0;
}

