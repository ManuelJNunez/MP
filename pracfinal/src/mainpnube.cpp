#include "nubeparticulas.h"
#include "definiciones.h"
#include <stdlib.h>
#include <iostream>

int main(){
	const int NCOLORES = 6;
	int ancho = 800, alto = 800;
	Color v[NCOLORES];
	vredimensiona(ancho, alto);

	v[0] = ROJO;
	v[1] = VERDE;
	v[2] = AZUL;
	v[3] = AMARILLO;
	v[4] = MAGENTA;
	v[5] = CYAN;

	srand(time(0));
	NubeParticulas base(3);

	//constructor de copia
	NubeParticulas nuevo(base);
	nuevo.Mover(ancho, alto);

	//constructor por defecto
	NubeParticulas otro;

	//sobrecarga de asignacion
	otro=nuevo;
	otro.Mover(ancho, alto);

	//mostrar
	cout << "\n Conjunto Inicial" << endl;
	cout << base;
	cout << "\n Conjunto Movido1" << endl;
	cout << nuevo;
	cout << "\n Conjunto Movido2" << endl;
	cout << otro;
	cout << endl;

	//probaremos el redimensionamiento
	int N;
	Particula p;
	while( tecla() != ESCAPE ){
		otro.Mover(ancho, alto);
		borra();
		for(int i = 0; i < otro.GetCardinal(); ++i){
			p = otro.ObtieneParticula(i);
			color(p.getColor());
			circulo_lleno(p.getX(), p.getY(), RADIO);
		}
		refresca();

	//agrego 1 particula al conjunto
	Particula nueva;
	nueva.setColor(v[rand()%5]);
	otro.AgregaParticula(nueva);
	espera(10);
	}

vcierra();
return 0;
}