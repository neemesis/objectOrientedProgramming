#include <iostream>
#include <string.h>
using namespace std;

class Automobile {
private:
	char *marka;
	int *registracija;
	int maximumBrzina;
public:
	Automobile() {registracija = new int[5];}
	Automobile(const char *marka, int reg[], int maximumBrzina);
	bool operator ==(Automobile const &from);
	friend ostream &operator <<(ostream &out, Automobile &from);
	int getBrzina() {return maximumBrzina;}
	void setRegistracija(int *reg);
	~Automobile();
};

void Automobile::setRegistracija(int reg[5]) {
	for (int i = 0; i < 5; ++i) {
		registracija[i] = reg[i];
	}
}

ostream &operator <<(ostream &out, Automobile &from) {
	out << "Marka: " << from.marka << " Registracija: [";
	for (int i = 0; i < 5; ++i) {
		out << from.registracija[i] << " ";
	}
	out << "]" << endl;
}

bool Automobile::operator ==(Automobile const &from) {
	for (int i = 0; i < 5; ++i) {
		if (registracija[i] != from.registracija[i]) return 0;
	}
	return 1;
}

Automobile::Automobile(const char *marka, int reg[], int maximumBrzina) {
	this -> marka = new char[strlen(marka)];
	strcpy(this -> marka, marka);
	registracija = new int[5];
	this -> maximumBrzina = maximumBrzina;
	setRegistracija(reg);
}

class RentACar {
private:
	char *ime;
	Automobile *car;
	int brojNaAvtomobili;
public:
	RentACar(const char *ime) {this -> ime = new char[strlen(ime)]; strcpy(this -> ime, ime); brojNaAvtomobili = 0;}
	RentACar &operator +=(Automobile const &from);
	RentACar &operator -=(Automobile const &from);
	void pecatiNadBrzina(int max);
};

void RentACar::pecatiNadBrzina(int max) {
	for (int i = 0; i < brojNaAvtomobili; ++i) {
		if (car[i].getBrzina() > max)
			cout << car[i];
	}
}

RentACar &RentACar::operator -=(Automobile const &from) {
	int total = 0;
	Automobile *tmp = new Automobile[brojNaAvtomobili];
	for (int i = 0; i < brojNaAvtomobili; ++i)
		if (!(car[i] == from))
			tmp[total++] = car[i];
	delete [] car;
	car = tmp;
	brojNaAvtomobili = total;
	return *this;
}

RentACar &RentACar::operator +=(Automobile const &from) {
	if (!brojNaAvtomobili) car = new Automobile[1];
	Automobile *tmp = new Automobile[brojNaAvtomobili + 1];
	for (int i = 0; i < brojNaAvtomobili; ++i) {
		tmp[i] = car[i];
	}
	tmp[brojNaAvtomobili++] = from;
	delete [] car;
	car = tmp;
	return *this;
}

int main() {
    RentACar agencija("FINKI-Car");
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        char marka[100];
        int registracija[5];
        int maximumBrzina;
        cin>>marka;
        for (int i=0; i<5; i++)
            cin>>registracija[i];
        cin>>maximumBrzina;
        Automobile nov=Automobile(marka,registracija,maximumBrzina);
        agencija+=nov;
    }
    char marka[100];
    int registracija[5];
    int maximumBrzina;
    cin>>marka;
    for (int i=0; i<5; i++)
        cin>>registracija[i];
    cin>>maximumBrzina;
    Automobile greshka=Automobile(marka,registracija,maximumBrzina);
    agencija-=greshka;
    agencija.pecatiNadBrzina(150);
    return 0;
}