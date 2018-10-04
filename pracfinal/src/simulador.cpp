#include "simulador.h"
#include "definiciones.h"

Simulador::Simulador( int ancho, int alto, int nro_p ): mi_nube(nro_p) {
	this->nro_p = nro_p;
	this->ancho = ancho;
	this->alto = alto;

	vredimensiona(this->ancho, this->alto);
}

Simulador::~Simulador(){
	vcierra();
}

void Simulador::Mover(){
	borra();
	mi_nube.Mover(ancho, alto);
}

void Simulador::Pintar(){
	Particula p;

	for(int i = 0; i < nro_p; ++i ){
		p = mi_nube.ObtieneParticula(i);
		color(p.getColor());
		circulo_lleno(p.getX(), p.getY(), RADIO);
	}

	refresca();
}

void Simulador::GestionaColisiones(){
	mi_nube.Colisiones();
}