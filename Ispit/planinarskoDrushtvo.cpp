#include <iostream>
#include <string.h>
using namespace std;

class PlDrustvo {
private:
	char *ime;
	int brTuri;
	int brClenovi;
public:
	PlDrustvo(const char *ime = "", int brTuri = 0, int brClenovi = 0);
	PlDrustvo operator +(PlDrustvo const &from);
	bool operator >(PlDrustvo const &from);
	bool operator <(PlDrustvo const &from);
	friend ostream &operator <<(ostream &out, PlDrustvo &from);
	int getClenovi() {return brClenovi;}
};

ostream &operator <<(ostream &out, PlDrustvo &from) {
	out << "Ime: " << from.ime << " Turi: " << from.brTuri << " Clenovi: " << from.brClenovi << endl;
}

bool PlDrustvo::operator >(PlDrustvo const &from) {
	if (brClenovi > from.brClenovi) return 1;
	return 0;
}

bool PlDrustvo::operator <(PlDrustvo const &from) {
	if (brClenovi < from.brClenovi) return 1;
	return 0;
}

PlDrustvo PlDrustvo::operator +(PlDrustvo const& from) {
	PlDrustvo temp;
	temp.brClenovi = brClenovi + from.brClenovi;
	if (brClenovi >= from.brClenovi) {
		temp.ime = new char [strlen(ime)];
		strcpy(temp.ime, ime);
		temp.brTuri = brTuri;
	} else {
		temp.ime = new char [strlen(from.ime)];
		strcpy(temp.ime, from.ime);
		temp.brTuri = from.brTuri;
	}
	return temp;
}

PlDrustvo::PlDrustvo(const char *ime, int brTuri, int brClenovi) {
	this -> ime = new char[strlen(ime)];
	strcpy(this -> ime, ime);
	this -> brTuri = brTuri;
	this -> brClenovi = brClenovi;
}

void najmnoguClenovi(PlDrustvo *drustva, int n) {
	int maxChlenovi = 0;
	int maxIndex;
	for (int i = 0; i < n; ++i) {
		if (drustva[i].getClenovi() > maxChlenovi) {
			maxChlenovi = drustva[i].getClenovi();
			maxIndex = i;
		}
	}
	cout << drustva[maxIndex];
}

int main() { 
	PlDrustvo drustva[3];
	PlDrustvo pl;
	for (int i = 0; i < 3; i++) {
		char ime[100];
		int brTuri;
		int brClenovi;
		cin >> ime;
		cin >> brTuri;
		cin >> brClenovi;
		PlDrustvo p(ime,brTuri,brClenovi);
		drustva[i] = p;
	}

	pl = drustva[0] + drustva[1];
	cout << pl;

	cout << "Najmnogu clenovi ima planinarskoto drustvo: ";
	najmnoguClenovi(drustva, 3);

	return 0;
}