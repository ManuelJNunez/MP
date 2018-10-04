#include <iostream>
#include <string>
#include "circulo.h"

using namespace std;

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