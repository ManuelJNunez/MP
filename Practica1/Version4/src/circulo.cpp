#include "circulo.h"
#include "punto.h"
#include <string>

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
