#include <iostream>
#include <string.h>
using namespace std;

class Potpisuvac {
private:
	char ime[20];
	char prezime[20];
	char embg[14];
public:
	Potpisuvac(char ime[], char prezime[], char embg[]);
	char *getEMBG() {return embg;}
};

Potpisuvac::Potpisuvac(char ime[] = "", char prezime[] = "", char embg[] = "") {
	strcpy(this -> ime, ime);
	strcpy(this -> prezime, prezime);
	strcpy(this -> embg, embg);
}

class Dogovor {
private:
	int brojNaDogovor;
	char kategorija[50];
	Potpisuvac potpishuvaci[3];
public:
	Dogovor(int brojNaDogovor, char kategorija[], Potpisuvac potpishuvaci[]);
	bool proverka();
};

bool Dogovor::proverka() {
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 3; ++j) {
			if (!strcmp(potpishuvaci[i].getEMBG(), potpishuvaci[j].getEMBG()))
				return 0;
		}
	}
	return 1;
}

Dogovor::Dogovor(int brojNaDogovor = 0, char kategorija[] = "", Potpisuvac potpishuvaci[] = 0) {
	this -> brojNaDogovor = brojNaDogovor;
	strcpy(this -> kategorija, kategorija);
	for (int i = 0; i < 3; ++i) {
		this -> potpishuvaci[i] = potpishuvaci[i];
	}
}

int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);
    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;
    	Dogovor d(broj, kategorija, p);
    	if(!d.proverka())
    	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
    	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}