#include <iostream>
#include <string.h>
using namespace std;

class Soba {
private:
	int tip;
	bool zafatena;
	char matichen[14];
	int vkupnoDenovi;
	int cenaNaSoba;
public:
	Soba(int t, bool z, const char m[], int v, int c);
	bool getZafatena() {return zafatena;}
	friend ostream &operator <<(ostream &out, Soba &from);
	bool operator ==(const Soba &from);
};

bool Soba::operator ==(const Soba &from) {
	if (tip != from.tip) return 0;
	if (zafatena != from.zafatena) return 0;
	if (strcmp(matichen, from.matichen)) return 0;
	if (vkupnoDenovi != from.vkupnoDenovi) return 0;
	if (cenaNaSoba != from.cenaNaSoba) return 0;
	return 1;
}

ostream &operator <<(ostream &out, Soba &from) {
	out << "Tip: " << from.tip << endl;
	out << "Zafatena: " << from.zafatena << endl;
	out << "Vkupno denovi: " << from.vkupnoDenovi << endl;
	out << "Cena: " << from.cenaNaSoba << endl;
	return out;
}

Soba::Soba(int t = 0, bool z = false, const char m[] = "", int v = 0, int c = 0) {
	tip = t;
	zafatena = z;
	strcpy(matichen, m);
	vkupnoDenovi = v;
	cenaNaSoba = c;
}

class Hotel {
private:
	char *ime;
	char lokacija[50];
	int vkupnoSobi;
	Soba *sobi;
	int budzhet;
	int dzvezdi;
public:
	Hotel(const char *name, const char lok[]);
	Hotel &operator +=(const Soba &from);
	Hotel &operator -=(const Soba &from);
	friend ostream &operator <<(ostream &out, Hotel &from);
	int slobodni_sobi();
};

ostream &operator <<(ostream &out, Hotel &from) {
	out << "Ime: " << from.ime << endl;
	out << "Lokacija: " << from.lokacija << endl;
	out << "Vkupno sobi: " << from.vkupnoSobi << endl;
	out << "Slobodni sobi: " << endl;
	for (int i = 0; i < from.vkupnoSobi; ++i) {
		if (!from.sobi[i].getZafatena()) {
			cout << from.sobi[i];
		}
	}
	return out;
}

Hotel &Hotel::operator +=(const Soba &from) {
	if (!vkupnoSobi) sobi = new Soba[1];
	Soba *tmp = new Soba[vkupnoSobi + 1];
	for (int i = 0; i < vkupnoSobi; ++i) {
		tmp[i] = sobi[i];
	}
	tmp[vkupnoSobi++] = from;
	delete [] sobi;
	sobi = tmp;
	return *this;
}

Hotel &Hotel::operator -=(const Soba &from) {
	int brojach = 0;
	Soba *tmp = new Soba[vkupnoSobi];
	for (int i = 0; i < vkupnoSobi; ++i) {
		if (!(sobi[i] == from)) {
			tmp[brojach++] = sobi[i];
		}
	}
	vkupnoSobi = brojach;
	delete [] sobi;
	sobi = tmp;
	return *this;
}

int Hotel::slobodni_sobi() {
	int total = 0;
	for (int i = 0; i < vkupnoSobi; ++i)
		if (!sobi[i].getZafatena())
			++total;
	return total;
}

Hotel::Hotel(const char *name, const char lok[]) {
	ime = new char[strlen(name)];
	strcpy(ime, name);
	strcpy(lokacija, lok);
}

int main() {
	Soba s(1, false, "marko", 30, 900);
	Hotel h("Slavija", "Ohrid");
	cout << "Soba:: " << endl << s << endl;
	h += s;
	cout << h << endl;
	h -= s;
	cout << h << endl;
	return 0;
}