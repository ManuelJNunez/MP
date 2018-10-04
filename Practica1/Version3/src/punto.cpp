#include <cmath>
#include <string>
#include "punto.h"

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
	return "(" + to_string(getX()) + "," + to_string(getX()) + ")";
}

double Punto::distancia(Punto p2){
	return sqrt( (pow((p2.getX() - getX()),2) - (pow(p2.getY() - getY()),2) );
}


Punto Punto::puntoMedio(Punto p2){
	Punto medio;

	medio.setX( (p2.x + x) / 2 );
	medio.setY( (p2.y + y) / 2 );

	return medio;
}
