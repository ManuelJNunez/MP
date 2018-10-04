#include "nubeparticulas.h"
#include <iostream>

using namespace std;

NubeParticulas::NubeParticulas(){
	capacidad = 1;
	nube = new Particula[capacidad];
	utils = capacidad;
}

NubeParticulas::NubeParticulas( int c ){
	capacidad = c;
	nube = new Particula[capacidad];
	utils = capacidad;
}

NubeParticulas::NubeParticulas(const NubeParticulas &otra){
	Copiar(otra);
}

NubeParticulas::~NubeParticulas(){
	delete[] nube;
}

void NubeParticulas::Copiar( const NubeParticulas &otra ){
	this->capacidad = otra.capacidad;
	this->utils = otra.utils;

	if( capacidad > 0 ){
		this->nube = new Particula[otra.capacidad];

		for( int i = 0; i < capacidad; ++i )
			this->nube[i] = otra.nube[i];
	}
}

int NubeParticulas::getCapacidad() const{
	return capacidad;
}

int NubeParticulas::GetCardinal() const{
	return utils;
}

void NubeParticulas::AgregaParticula(Particula nueva){
	const int TAM_BLOQUE = 10;
	utils++;

	if( utils >= capacidad ){
		capacidad += TAM_BLOQUE;

	Particula* newcloud;
	newcloud = new Particula[capacidad];

	for( int i = 0; i <= utils; ++i )
		newcloud[i] = nube[i];

	if( nube != 0 )
		delete []nube;

	nube = newcloud;
	}

	nube[utils-1] = nueva;
}

void NubeParticulas::BorraParticula(int pos){
	for( int i = pos; i < utils; ++i  ){
		nube[i] = nube[i+1];				//sobrecargué el operador = en la clase partícula para que no se pasen por referencia
	}

	utils--;
}

Particula NubeParticulas::ObtieneParticula(int pos) const{
	return nube[pos];
}

void NubeParticulas::Mover(int ancho, int alto){
	for( int i = 0; i < utils; ++i )
		nube[i].mueve_particula(ancho, alto);
}

void NubeParticulas::Colisiones(){
	for( int i = 0; i <= utils; ++i )
			for( int j = i+1; j <= utils ; ++j )
				if(nube[i].Colision(nube[j]))
					nube[i].Rebote(nube[j]);
}

NubeParticulas& NubeParticulas::operator=( const NubeParticulas &otra ){
	if( &otra != this ){
		delete[] this->nube;

		Copiar(otra);
	}

	return *this;
}

ostream& operator<<( ostream &flujo, NubeParticulas &cloud ){
	for( int i = 0; i < cloud.GetCardinal(); ++i ){
		flujo << endl << "Posición partícula (" << i << ")(x,y): (" << cloud.ObtieneParticula(i).getX() << "," << cloud.ObtieneParticula(i).getY() << ")";
		flujo << endl;
	}

	flujo << endl;
	return flujo;
}