#include <iostream>
#include <string.h>
using namespace std;

class Agol {
private:
	int stepeni;
	int minuti;
	int sekundi;
public:
	void setDeg(int stepeni) {this -> stepeni = stepeni;}
	void setMin(int minuti) {this -> minuti = minuti;}
	void setSec(int sekundi) {this -> sekundi = sekundi;}
	int count() {return 360 * stepeni + 60 * minuti + sekundi;}
};

bool proveri(int deg, int min, int sec) {
	if (min > 60 || min < 0) return 0;
	if (sec > 60 || sec < 0) return 0;
	return 1;
}

int main() {
    
    Agol a1;
    int deg, min, sec;
    cin >> deg >> min >> sec;
    
    if (proveri(deg, min, sec)) {
    
    	a1.setDeg(deg);
        a1.setMin(min);
        a1.setSec(sec);
        cout << a1.count();
        
    } else cout << "Ne validni vrednosti za agol" << endl;
    
    return 0;
}
