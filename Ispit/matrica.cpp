#include <iostream>
#include <string.h>
using namespace std;

class Matrica {
private:
	float matrica[10][10];
	int brojRedici;
	int brojKoloni;
public:
	friend istream &operator >>(istream &in, Matrica &from);
	friend ostream &operator <<(ostream &out, Matrica &from);
	Matrica operator +(int broj);
	Matrica operator -(Matrica const &from);
	Matrica operator *(Matrica const &from);
};

Matrica Matrica::operator *(Matrica const& mat) {
	Matrica temp;
	temp.brojRedici = mat.brojRedici;
	temp.brojKoloni = mat.brojKoloni;
	for(int i = 0; i < mat.brojRedici; i++)
		for(int j = 0; j < mat.brojKoloni; j++) {
			float t = 0;
			for(int k = 0; k < mat.brojRedici; k++)
				t += matrica[i][k] * mat.matrica[k][j];
			temp.matrica[i][j] = t;
	}
	return temp;
}

Matrica Matrica::operator -(Matrica const &from) {
	for (int i = 0; i < brojRedici; ++i) {
		for (int j = 0; j < brojKoloni; ++j) {
			matrica[i][j] -= from.matrica[i][j];
		}
	}
	return *this;
}

Matrica Matrica::operator +(int broj) {
	for (int i = 0; i < brojRedici; ++i) {
		for (int j = 0; j < brojKoloni; ++j) {
			matrica[i][j] += broj;
		}
	}
	return *this;
}

istream &operator >>(istream &in, Matrica &from) {
	in >> from.brojRedici >> from.brojKoloni;
	for (int i = 0; i < from.brojRedici; ++i) {
		for (int j = 0; j < from.brojKoloni; ++j) {
			in >> from.matrica[i][j];
		}
	}
	return in;
}

ostream &operator <<(ostream &out, Matrica &from) {
	for (int i = 0; i < from.brojRedici; ++i) {
		for (int j = 0; j < from.brojKoloni; ++j) {
			out << from.matrica[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

int main() {
	Matrica A, B, C;
	cin >> A >> B >> C;
	Matrica D = B * C;
	Matrica R = A - D + 2;
	cout << R;
	return 0;
}