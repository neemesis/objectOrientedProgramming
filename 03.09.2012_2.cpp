#include <iostream>
#include <string.h>
using namespace std;

class Let {
protected:
	int brojNaAvion;
	int vremetraenjeNaLet;
	char portalZaIzlez[4];
	int brojSedishta;
	double osnovnaCena;
	char destinacijaGrad[20];
public:
	Let(int broj, int vreme, const char portal[], int brojs, double cena, const char dest[]);
	virtual double vratiCena() = 0;
	virtual ~Let() {cout << "Delete Let!";}
	virtual void pechati() = 0;
	friend ostream &operator <<(ostream &out, Let *from) {return out << "Osnoven Let!";}
};

Let::Let(int broj = 0, int vreme = 0, const char portal[] = "", int brojs = 0, double cena = 0, const char dest[] = "") {
	brojNaAvion = broj;
	vremetraenjeNaLet = vreme;
	strcpy(portalZaIzlez, portal);
	brojSedishta = brojs;
	osnovnaCena = cena;
	strcpy(destinacijaGrad, dest);
}

class Lokalen : public Let {
private:
	double popust;
	bool uzhina;
public:
	Lokalen(int broj, int vreme, const char portal[], int brojs, double cena, const char dest[], double po, bool uzh);
	double vratiCena();
	friend ostream &operator <<(ostream &out, Lokalen *from) {return out << "Lokalen Let!";}
	void pechati() {cout << "Lokalen";}
};

double Lokalen::vratiCena() {
	return osnovnaCena * (1 - popust);
}

Lokalen::Lokalen(int broj = 0, int vreme = 0, const char portal[] = "", int brojs = 0, double cena = 0, const char dest[] = "", double po = 0, bool uzh = false) : Let(broj, vreme, portal, brojs, cena, dest) {
	popust = po;
	uzhina = uzh;
}

class Internacionalen : public Let {
private:
	int sedishtaPrvaKlasa;
	double cenaNaLet;
	double taksa;
	char drzhava[30];
public:
	Internacionalen(int broj, int vreme, const char portal[], int brojs, double cena, const char dest[], int spk, double cnl, double tax, const char drz[]);
	double vratiCena();
	void pechati() {cout << "Internacionalen";}
};

double Internacionalen::vratiCena() {
	return ((osnovnaCena + cenaNaLet) / 2) + taksa;
}

Internacionalen::Internacionalen(int broj = 0, int vreme = 0, const char portal[] = "", int brojs = 0, double cena = 0, const char dest[] = "", int spk = 0, double cnl = 0, double tax = 0, const char drz[] = "") : Let(broj, vreme, portal, brojs, cena, dest) {
	sedishtaPrvaKlasa = spk;
	cenaNaLet = cnl;
	taksa = tax;
	strcpy(drzhava, drz);
}

Let *najevtin_let(Let **letovi, int broj) {
	double minLet = 99999;
	int minI;
	for (int i = 0; i < broj; ++i) {
		if (letovi[i] -> vratiCena() < minLet) {
			minLet = letovi[i] -> vratiCena();
			minI = i;
		}
	}
	return letovi[minI];
}

int main() {
	Let **letovi = new Let *[3];
	letovi[0] = new Lokalen(10, 20, "yum", 200, 150, "skopje", 0.1, 1);
	letovi[1] = new Lokalen(20, 30, "bla", 150, 100, "kumanovo", 0.2, 0);
	letovi[2] = new Internacionalen(20, 40, "ble", 150, 20, "sofija", 20, 50, 10, "Bulgaria");

	cout << letovi[2] -> vratiCena() << endl;
	letovi[1] -> pechati();

	Let *tmp = najevtin_let(letovi, 3);
	tmp -> pechati();
	return 0;
}