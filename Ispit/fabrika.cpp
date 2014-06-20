#include <iostream>
#include <string.h>
using namespace std;

class Rabotnik {
private:
	char ime[30];
	char prezime[30];
	int plata;
public:
	Rabotnik(const char ime[], const char prezime[], int plata);
	int getPlata() {return plata;}
	void pecati() {cout << "Ime: " << ime << endl << "Prezime: " << prezime << endl << "Plata: " << plata << endl;}
};

Rabotnik::Rabotnik(const char ime[] = "", const char prezime[] = "", int plata = 0) {
	strcpy(this -> ime, ime);
	strcpy(this -> prezime, prezime);
	this -> plata = plata;
}

class Fabrika {
private:
	Rabotnik rabotnici[100];
	int brojVraboteni;
public:
	Fabrika(Rabotnik rabotnici[], int brojVraboteni);
	void pecatiVraboteni();
	void pecatiSoPlata(int plata);
};

void Fabrika::pecatiSoPlata(int plata) {
	for (int i = 0; i < brojVraboteni; ++i) {
		if (rabotnici[i].getPlata() >= plata)
			rabotnici[i].pecati();
	}
}

void Fabrika::pecatiVraboteni() {
	for (int i = 0; i < brojVraboteni; ++i)
		rabotnici[i].pecati();
}

Fabrika::Fabrika(Rabotnik *rabotnici, int brojVraboteni) {
	for (int i = 0; i < brojVraboteni; ++i) {
		this -> rabotnici[i] = rabotnici[i];
	}
	this -> brojVraboteni = brojVraboteni;
}

int main() { 
    int n; 
    cin >> n; 
    Rabotnik rabotnik[n]; 
    for (int i = 0; i < n; ++i) { 
        char im[30]; 
        cin >> im; 
        char p[30]; 
        cin >> p; 
        int pl; 
        cin >> pl; 
        rabotnik[i] = Rabotnik(im, p, pl); 
    } 
    Fabrika fab(rabotnik, n);
    int minPlata; 
    cin >> minPlata; 
    cout << "Site vraboteni:" << endl;
    fab.pecatiVraboteni(); 
    cout << "Vraboteni so plata povisoka od " << minPlata << " :" << endl;
    fab.pecatiSoPlata(minPlata); 
  
    return 0; 
}