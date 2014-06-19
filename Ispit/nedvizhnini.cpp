#include <iostream>
#include <string.h>
using namespace std;

class Nedvizhnina {
protected:
	char *adresa;
	int kvadratura;
	int cenaZaKvadrat;
public:
	Nedvizhnina(char *adresa, int kvadratura, int cenaZaKvadrat);
	int cena() {return cenaZaKvadrat * kvadratura;}
	void pecati() {cout << adresa << endl << kvadratura << endl << cenaZaKvadrat << endl;}
	double danokNaImot() {return 0.05 * cena();}
	friend istream &operator >>(istream &in, Nedvizhnina &from);
	char *getAdresa() {return adresa;}
};

istream &operator >>(istream &in, Nedvizhnina &from) {
	in >> from.adresa >> from.kvadratura >> from.cenaZaKvadrat;
	return in;
}

Nedvizhnina::Nedvizhnina(char *adresa = "", int kvadratura = 0, int cenaZaKvadrat = 0) {
	this -> adresa = new char[strlen(adresa)];
	this -> kvadratura = kvadratura;
	this -> cenaZaKvadrat = cenaZaKvadrat;
}

class Vila : public Nedvizhnina {
private:
	int danokNaLuksuz;
public:
	Vila(char *adresa, int kvadratura, int cenaZaKvadrat, int danokNaLuksuz);
	void pecati() {Nedvizhnina::pecati(); cout << danokNaLuksuz << endl;}
	double danokNaImot() {return Nedvizhnina::danokNaImot() * danokNaLuksuz;}
	friend istream &operator >>(istream &in, Vila &from);
};

istream &operator >>(istream &in, Vila &from) {
	in >> from.adresa >> from.kvadratura >> from.cenaZaKvadrat >> from.danokNaLuksuz;
	return in;
}

Vila::Vila(char *adresa = "", int kvadratura = 0, int cenaZaKvadrat = 0, int danokNaLuksuz = 0) : Nedvizhnina(adresa, kvadratura, cenaZaKvadrat) {
	this -> danokNaLuksuz = danokNaLuksuz;
}

int main(){
    Nedvizhnina n;
    Vila v;
    cin>>n;
    cin>>v;
    n.pecati();
    cout<<"Danok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati();
    cout<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}