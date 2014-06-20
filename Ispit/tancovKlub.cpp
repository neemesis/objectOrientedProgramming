#include <iostream>
#include <string.h>
using namespace std;

class Clen {
private:
	char ime[50];
	char prezime[50];
	int stepenVoKlubot;
public:
	Clen(const char ime[] = "", const char prezime[] = "", int stepenVoKlubot = 0);
	Clen operator ++() {++stepenVoKlubot;}
	Clen operator ++(int) {++stepenVoKlubot;}
	friend ostream &operator <<(ostream &out, Clen &from);
	bool operator !=(Clen const &from) {return stepenVoKlubot != from.stepenVoKlubot;}
};

ostream &operator <<(ostream &out, Clen &from) {
	out << from.ime << " " << from.prezime << " " << from.stepenVoKlubot << endl;
}

Clen::Clen(const char ime[], const char prezime[], int stepenVoKlubot) {
	strcpy(this -> ime, ime);
	strcpy(this -> prezime, prezime);
	this -> stepenVoKlubot = stepenVoKlubot;
}

class Klub {
private:
	char ime[100];
	Clen *clen;
	int vkupnoClenovi;
public:
	Klub(const char ime[] = "") {strcpy(this -> ime, ime); vkupnoClenovi = 0;}
	Klub &operator +=(const Clen &from);
	friend ostream &operator <<(ostream &out, Klub &from);
	Klub &novKlub(Clen &from);
};

Klub &Klub::novKlub(Clen &from) {
	Klub *temp = new Klub(ime);
	int total = 0;
	for (int i = 0; i < vkupnoClenovi; ++i) {
		if (!(clen[i] != from)) {
			++clen[i];
			(*temp) += clen[i];
			++total;
		}
	}
	temp -> vkupnoClenovi = total;
	return *temp;
}

ostream &operator <<(ostream &out, Klub &from) {
	out << from.ime << endl;
	for (int i = 0; i < from.vkupnoClenovi; ++i) {
		cout << from.clen[i];
	}
}

Klub &Klub::operator +=(const Clen &from) {
	if (!vkupnoClenovi) clen = new Clen[1];
	Clen *temp = new Clen[vkupnoClenovi + 1];
	for (int i = 0; i < vkupnoClenovi; ++i) {
		temp[i] = clen[i];
	}
	temp[vkupnoClenovi++] = from;
	delete [] clen;
	clen = temp;
	return *this;
}

int main()
{
    Clen clen;
    int n, stepen;
    char ime[30], prezime[30];
	cin >> ime >> n;
    Klub k1(ime);
    for(int i = 0; i < n; i++){
    	cin >> ime >> prezime >> stepen;
        Clen c(ime, prezime, stepen);
        k1 += c;
        clen = c;
    }
    Klub k2 = k1.novKlub(clen);
    cout << k2;
	return 0;
}