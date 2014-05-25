#include <iostream>
#include <string.h>
using namespace std;

class Kartichka {
protected:
	double saldo;
	char id[16];
public:
	Kartichka(const char *id = "", double saldo = 0) {this -> saldo = saldo; strcpy(this -> id, id);}
	void uplati(double uplati) {saldo += uplati;}
	virtual double isplati(double isplati) {saldo -= isplati;}
	virtual double isplati(double isplati, int limit);
	void prikaziSaldo() {cout << id << ": " << saldo << endl;}
};

double Kartichka::isplati(double isplati, int limit) {
	if (this -> saldo + limit > isplati) {
		this -> saldo -= isplati;
		return isplati;
	}
	return 0;
}

class Master : public Kartichka {
private:
	double limit;
	const static double popust1;
	static double popust2;
public:
	Master(const char *id = "", double saldo = 0, double limit = 0) : Kartichka(id, saldo) {this -> limit = limit;}
	void setPopust(double popust) {popust2 = popust;}
	double isplati(double isplati);
};
const double Master::popust1 = 0.3;
double Master::popust2 = 0.1;

double Master::isplati(double isplati) {
	double total;
	if (this -> limit < 6000)
		total = isplati * (1 - popust1);
	else total = isplati * (1 - popust2);
	return Kartichka::isplati(total, limit);
}

class Maestro : public Kartichka {
private:
	char lozinka[10];
	const static double popust;
public:
	Maestro(const char *id = "", double saldo = 0, const char *lozinka = "") : Kartichka(id, saldo) {strcpy(this -> lozinka, lozinka);}
	const double getPopust() {return popust;}
	double isplati(double isplati) {double total = isplati * (1 - popust); return Kartichka::isplati(total);}
};
const double Maestro::popust = 0.5;

int main() {
	Master k1("Petre", 150, 1880);
	Maestro k2("Panche", 234, "nemalozinka");
	k1.prikaziSaldo();
	k2.prikaziSaldo();
	k1.uplati(999);
	k2.isplati(500);
	k1.prikaziSaldo();
	k2.prikaziSaldo();
	return 0;
}