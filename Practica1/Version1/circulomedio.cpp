/**
   @file circulomedio.cpp
   @brief Calcula círculo con centro en medio de dos círculos y radio la mitad de la distancia
   @warning Módulo no definitivo (creado para ser modificado)

// si quiere utilizar la funcion to_string(), recuerde agregar -std=c++0x (o -std=c++11) a las opciones del compilador

**/

#include <iostream>
#include <cmath> 
#include <string>

using namespace std;

const double PI = 3.14159265;
class Punto {
private:
    double x; // coordenada x del punto
    double y; // coordenada y del punto

public:
    Punto(); //constructor. Pone a 0 las dos coordenadas
    Punto(double px, double py); // constructor. Inicializa un punto con dos valores x y
    double getX(); 
    double getY(); 
    void setX(double newXValue); 
    void setY(double newYValue); 
    string toString(); ///<  devuelve el contenido del punto como un string
    double distancia(Punto p2); // calcula la distancia a otro punto
    Punto puntoMedio(Punto p2); //devuelve el punto medio entre el objeto implicito y p2
};

Punto::Punto():x(0),y(0) {
}

Punto::Punto(double px, double py):x(px),y(py) {
}

double Punto::getX() {
	return x;
}

double Punto::getY() {
	return y;
}

void Punto::setX(double px) {
	x = px;
}

void Punto::setY(double py) {
	y = py;
}

string Punto::toString() {
	string salida;

	salida = "(";
	salida += to_string(x);
	salida += ",";
	salida += to_string(y);
	salida += ")";

	return salida; 
}

double Punto::distancia(Punto p2){
	return sqrt( (pow(p2.x - x,2)) - (pow(p2.y - y,2)) );
}


Punto Punto::puntoMedio(Punto p2){
	Punto medio;

	medio.setX( (p2.x + x) / 2 );
	medio.setY( (p2.y + y) / 2 );

	return medio;
}


class Circulo {
private:
    Punto centro; // Centro del círculo
    double radio; // radio del círculo

public:
    Circulo(); // Constructor: Pone a 0 el punto y el radio
    Circulo(Punto centro, double rradio); // Constructor: Inicializa el círculo con un centro y un radio
    void set(Punto centro, double rradio); // Asigna el centro y el radio a un circulo
    Punto getCentro(); 
    double getRadio(); 
    string toString(); // devuelve el contenido del circulo como un string
    double area(); // Devuelve el área de un círculo
    double distancia (Circulo c2);
    bool interior (Punto p); // true si p está contenido en el círculo
};

Circulo::Circulo():centro(0,0), radio(0) {
}

Circulo::Circulo(Punto p, double rradio):centro(p),radio(rradio) {
}

void Circulo::set(Punto p, double rradio) {
	radio = rradio;
	centro = p;
}


Punto Circulo::getCentro()  {
	return centro;
}

double Circulo::getRadio()  {
	return radio;
}

string Circulo::toString() {
	return centro.toString();
}

double Circulo::area() {
    return PI * radio * radio;
}

// devuelve la distancia entre sus centros
double Circulo::distancia (Circulo c2){
	return centro.distancia(c2.centro);
}

//Comprueba si un punto es interior al círculo
bool Circulo::interior (Punto p){
	return centro.distancia(p) < radio;
}


int main()
{
	Punto centro;
	Circulo c1, c2, c3;
	double x, y;
	double radio;

	// leer datos para circulo 1
	cout << "Ingrese la coordenada x e y del círculo 1 (separada por espacio): ";
	cin >> x >> y;

	centro.setX(x);
	centro.setY(y);

	cout << "Ingrese el radio del circulo 1: ";
	cin >> radio;

	c1.set(centro, radio);
	
	// leer datos para circulo 2
	cout << "Ingrese la coordenada x e y del círculo 2 (separada por espacio): ";
	cin >> x >> y;

	centro.setX(x);
	centro.setY(y);

	cout << "Ingrese el radio del circulo 2: ";
	cin >> radio;

	c2.set(centro, radio);
 
    // realizar los cálculos
	centro = c1.getCentro().puntoMedio(c2.getCentro());

	if(c1.getRadio() <= c2.getRadio())
		radio = (c2.getRadio() - c1.getRadio()) / 2;
	else
		radio = (c1.getRadio() - c2.getRadio()) / 2;

	c3.set(centro, radio);

	// mostrar resultados
    cout << "\nLos circulos son\n";
	cout << "Circulo 1 -> " << c1.toString() << ", area: " << c1.area() << endl;
	cout << "Circulo 2 -> " << c2.toString() << ", area: " << c2.area() << endl;
	cout << "Circulo 3 -> " << c3.toString() << ", area: " << c3.area() << endl;
    
    cout << endl;

    return 0;
}

/* Fin: circulomedio.cpp */
