#include <iostream>
#include <string.h>
using namespace std;

class GeometriskoTelo {
protected:
	double visina;
public:
	GeometriskoTelo(double visina = 0) {this -> visina = visina;}
	virtual void pecati() = 0;
	virtual double volumen() = 0;
	double getVisina() {return visina;}
};

class Cilinder : public GeometriskoTelo {
protected:
	double radius;
public:
	Cilinder(double visina = 0, double radius = 0) : GeometriskoTelo(visina) {this -> radius = radius;}
	void pecati() {cout << "Cilinder: " << "h: " << visina << " r: " << radius << endl;}
	double volumen() {return 3.14 * radius * radius * visina;}
};

class Konus : public GeometriskoTelo {
private:
	double radius;
public:
	Konus(double visina = 0, double radius = 0) : GeometriskoTelo(visina) {this -> radius = radius;}
	void pecati() {cout << "Konus: " << "h: " << visina << " r: " << radius << endl;}
	double volumen() {return (3.14 * radius * radius * visina) / 3.0;}
};

class Kvadar : public GeometriskoTelo {
private:
	double a;
	double b;
public:
	Kvadar(double visina = 0, double a = 0, double b = 0) : GeometriskoTelo(visina) {this -> a = a; this -> b = b;}
	void pecati() {cout << "Kvadar: " << "h: " << visina << " a: " << a << " b: " << b << endl;}\
	double volumen() {return a * b * visina;}
};

int main() {
	GeometriskoTelo **geom = new GeometriskoTelo *[3];
	geom[0] = new Cilinder(10, 3);
	geom[1] = new Konus(30, 3);
	geom[2] = new Kvadar(10, 2, 2);
	geom[0] -> pecati();
	cout << "Volumen: " << geom[0] -> volumen() << endl;
	geom[1] -> pecati();
	cout << "Volumen: " << geom[1] -> volumen() << endl;
	geom[2] -> pecati();
	cout << "Volumen: " << geom[2] -> volumen() << endl;
	return 0;
}