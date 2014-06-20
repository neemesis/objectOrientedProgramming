#include <iostream>
#include <string.h>
using namespace std;

class Masa {
private:
	int dolzina;
	int sirina;
public:
	Masa(int sirina = 0, int dolzina = 0) {this -> dolzina = dolzina; this -> sirina = sirina;}
	void pecati() {cout << "Masa: " << dolzina << " " << sirina << endl;}
};

class Soba {
private:
	Masa masa;
	int dolzina;
	int sirina;
public:
	Soba(int sirina, int dolzina, Masa masa);
	void pecati();
};

void Soba::pecati() {
	cout << "Soba: " << dolzina << " " << sirina << endl;
	masa.pecati();
}

Soba::Soba(int sirina = 0, int dolzina = 0, Masa masa = 0) {
	this -> sirina = sirina;
	this -> dolzina = dolzina;
	this -> masa = masa;
}

class Kukja {
private:
	Soba soba;
	char adresa[50];
public:
	Kukja(Soba soba = 0, char adresa[] = "") {this -> soba = soba; strcpy(this -> adresa, adresa);}
	void pecati();
};

void Kukja::pecati() {
	cout << "Adresa: " << adresa << endl;
	soba.pecati();
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}
    
    return 0;
}