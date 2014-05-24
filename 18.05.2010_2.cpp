#include <iostream>
#include <string.h>
using namespace std;

class Casovnik {
protected:
	int chas;
	int minuti;
	int sekundi;
public:
	Casovnik(int chas, int minuti, int sekundi);
	virtual void vreme() = 0;
	bool operator ==(const Casovnik &from);
};

bool Casovnik::operator ==(const Casovnik &from) {
	if (sekundi != from.sekundi) return 0;
	if (minuti != from.minuti) return 0;
	return 1;
}

Casovnik::Casovnik(int chas = 0, int minuti = 0, int sekundi = 0) {
	this -> chas = chas;
	this -> minuti = minuti;
	this -> sekundi = sekundi;
}

class DigitalenCasovnik : public Casovnik {
private:
	int stotinki;
public:
	DigitalenCasovnik(int chas, int minuti, int sekundi, int stotinki);
	void vreme();
};

void DigitalenCasovnik::vreme() {
	cout << chas << ":" << minuti << ":" << sekundi << ":" << stotinki << endl;
}

DigitalenCasovnik::DigitalenCasovnik(int chas, int minuti, int sekundi, int stotinki) : Casovnik(chas, minuti, sekundi) {
	try {
		this -> stotinki = stotinki;
		if (stotinki < 0 || stotinki > 99) throw 4;
		if (chas < 0 || chas > 23) throw 1;
		if (minuti < 0 || minuti > 59) throw 2;
		if (sekundi < 0 || sekundi > 55) throw 3;
	} catch (int x) {
		if (x == 1) {
			cout << "Greshka vo chasovite!" << endl;
			chas = -1;
		}
		if (x == 2) {
			cout << "Greshka vo minuti" << endl;
			minuti = -1;
		}
		if (x == 3) {
			cout << "Greshka vo sekundi" << endl;
			sekundi = -1;
		}
		if (x == 4) {
			cout << "Greshka vo stotinki!" << endl;
			stotinki = -1;
		}
	}
}

class AnalogenCasovnik : public Casovnik {
private:
	bool delOdDenot;
public:
	AnalogenCasovnik(int chas, int minuti, int sekundi, bool delOdDenot);
	void vreme();
};

void AnalogenCasovnik::vreme() {
	cout << chas << ":" << minuti << ":" << sekundi;
	if (delOdDenot) cout << " AM" << endl;
	else cout << " PM" << endl;
}

AnalogenCasovnik::AnalogenCasovnik(int chas = 0, int minuti = 0, int sekundi = 0, bool delOdDenot = 0) : Casovnik(chas, minuti, sekundi) {
	try {
		if (chas < 0 || chas > 12) throw 1;
		if (minuti < 0 || minuti > 59) throw 2;
		if (sekundi < 0 || sekundi > 55) throw 3;
	} catch (int x) {
		if (x == 1) {
			cout << "Greshka vo chasovite!" << endl;
			chas = -1;
		}
		if (x == 2) {
			cout << "Greshka vo minuti" << endl;
			minuti = -1;
		}
		if (x == 3) {
			cout << "Greshka vo sekundi" << endl;
			sekundi = -1;
		}
	}
	this -> delOdDenot = delOdDenot;
}

void Pechati(Casovnik **v, int n) {
	for (int i = 0; i < n; ++i) {
		v[i] -> vreme();
	}
}

int main() {
	Casovnik **v = new Casovnik *[5];
	v[0] = new DigitalenCasovnik(16,34,9,78);
	v[1] = new AnalogenCasovnik(4, 34, 9, 0);
	v[2] = new DigitalenCasovnik(12, 00, 1, 00);
	v[3] = new AnalogenCasovnik(12, 00, 01, 0);
	v[4] = new DigitalenCasovnik(00, 12, 34, 56);
	DigitalenCasovnik d1(0, 15, 24, 8);
	AnalogenCasovnik a1(12, 15, 24, 0);
	Pechati(v, 5);
	if (d1 == a1) cout << "Pokazhuvaat isto vreme!" << endl;
	else cout << "Pokazhuvaat razlichno vreme!" << endl;
	return 0;
}