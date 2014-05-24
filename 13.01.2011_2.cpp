#include <iostream>
#include <string.h>
using namespace std;

class Fotoaparat {
protected:
	char model[50];
	double osnovnaCena;
	double rezolucija;
public:
	Fotoaparat(const char model[], double osnovnaCena, double rezolucija);
	virtual double vratiCena() = 0;
	friend ostream &operator <<(ostream &out, Fotoaparat &from);
};

ostream &operator <<(ostream &out, Fotoaparat &from) {
	out << "Model: " << from.model << endl;
	out << "Osnovna Cena: " << from.osnovnaCena << endl;
	out << "Rezolucija: " << from.rezolucija << endl;
	return out;
}

Fotoaparat::Fotoaparat(const char model[] = "", double osnovnaCena = 0, double rezolucija = 0) {
	strcpy(this -> model, model);
	this -> osnovnaCena = osnovnaCena;
	this -> rezolucija = rezolucija;
}

class DSLR : public Fotoaparat {
private:
	char vidNaObjektiv[20];
	double cenaNaObjektiv;
public:
	DSLR(const char model[], double osnovnaCena, double rezolucija, const char vidNaObjektiv[], double cenaNaObjektiv);
	double vratiCena();
	friend ostream &operator <<(ostream &out, DSLR &from);
};

ostream &operator <<(ostream &out, DSLR &from) {
	out << (Fotoaparat&)from;
	out << "Vid na objektiv: " << from.vidNaObjektiv << endl;
	out << "Cena na objektiv: " << from.cenaNaObjektiv << endl;
	return out;
}

double DSLR::vratiCena() {
	if (rezolucija >= 15) return osnovnaCena * 1.15 + cenaNaObjektiv;
	return osnovnaCena + cenaNaObjektiv;
}

DSLR::DSLR(const char model[] = "", double osnovnaCena = 0, double rezolucija = 0, const char vidNaObjektiv[] = "", double cenaNaObjektiv = 0) : Fotoaparat(model, osnovnaCena, rezolucija) {
	strcpy(this -> vidNaObjektiv, vidNaObjektiv);
	this -> cenaNaObjektiv = cenaNaObjektiv;
}

class Kompaktni : public Fotoaparat {
private:
	bool vidNaZoom;
public:
	Kompaktni(const char model[], double osnovnaCena, double rezolucija, bool vidNaZoom);
	double vratiCena();
	friend ostream &operator <<(ostream &out, Kompaktni &from);
};

ostream &operator <<(ostream &out, Kompaktni &from) {
	out << (Fotoaparat&)from;
	out << "Vid na zoom: " << from.vidNaZoom << endl;
	return out;
}

double Kompaktni::vratiCena() {
	double cena = osnovnaCena;
	if (rezolucija >= 10) cena *= 1.12;
	if (vidNaZoom) cena *= 1.1;
	return cena;
}

Kompaktni::Kompaktni(const char model[] = "", double osnovnaCena = 0, double rezolucija = 0, bool vidNaZoom = false) : Fotoaparat(model, osnovnaCena, rezolucija) {
	this -> vidNaZoom = vidNaZoom;
}

Fotoaparat &NajmalaCena(Fotoaparat **f, int n) {
	Fotoaparat *tmp = f[0];
	for (int i = 0; i < n; ++i) {
		if (f[i] -> vratiCena() < tmp -> vratiCena())
			tmp = f[i];
	}
	return *tmp;
}

int main() {
	Fotoaparat **f = new Fotoaparat *[3];
	f[0] = new DSLR("DXL", 50, 15, "ubav", 2);
	f[1] = new Kompaktni("SXY", 100, 12, true);
	f[2] = new DSLR("DeNZi", 8, 18, "blue", 3);
	cout << NajmalaCena(f, 3);

	return 0;
}