#include <iostream>
#include <string.h>
using namespace std;

class Kompjuter {
private:
	char ime[15];
	char ip[15];
	int vreme;
public:
	Kompjuter(const char name[], const char ip[], int time);
	friend ostream &operator <<(ostream &out, Kompjuter &from);
	char *getIP() {return ip;}
};

ostream &operator <<(ostream &out, Kompjuter &from) {
	out << "Ime: " << from.ime << endl;
	out << "IP: " << from.ip << endl;
	out << "Vreme: " << from.vreme << endl;
	return out;
}

Kompjuter::Kompjuter(const char name[] = "", const char ip[] = "", int time = 0) {
	strcpy(ime, name);
	strcpy(this->ip, ip);
	vreme = time;
}

class Host {
private:
	char *ime;
	Kompjuter *komp;
	int broj;
public:
	Host(const char *name, int broj);
	friend ostream &operator <<(ostream &out, Host &from);
	Host &operator +=(const Kompjuter &from);
	int proveri();
};

Host &Host::operator +=(const Kompjuter &from) {
	if (!broj) komp = new Kompjuter[1];
	Kompjuter *tmp = new Kompjuter[broj + 1];
	for (int i = 0; i < broj; ++i) {
		tmp[i] = komp[i];
	}
	tmp[broj++] = from;
	delete [] komp;
	komp = tmp;
	return *this;
}

int Host::proveri() {
	int total = 0;
	for (int i = 0; i < broj; ++i) {
		char *proveri2 = new char[strlen(komp[i].getIP())];
		strcpy(proveri2, komp[i].getIP());
		if (strlen(proveri2) == 15 && proveri2[3] == '.' && proveri2[7] == '.' && proveri2[11] == '.')
			++total;
	}
	return total;
}

ostream &operator <<(ostream &out, Host &from) {
	for (int i = 0; i < from.broj; ++i) {
		out << from.komp[i];
	}
	return out;
}

Host::Host(const char *name = "", int total = 0) {
	ime = new char[strlen(name)];
	strcpy(ime, name);
	broj = total;
}

int main() {
	Kompjuter komp("Marko", "255.123.548.654", 60);
	Kompjuter komp2("Ivana", "32.121.538.654", 60);
	Kompjuter komp3("Fo", "255.123.548.654", 60);
	Kompjuter komp4("MDo", "255.1238748.654", 60);
	Kompjuter komp5("MaWQEo", "24889123.548.654", 60);
	cout << komp;
	Host host("Host");
	host += komp;
	host += komp2;
	host += komp3;
	host += komp4;
	host += komp5;
	cout << host;
	cout << host.proveri();
	return 0;
}
