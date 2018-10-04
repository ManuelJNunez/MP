#ifndef NUBEPARTICULAS
#define NUBEPARTICULAS
#include "particula.h"
#include <iostream>

using namespace std;

class NubeParticulas{
	private:
		Particula *nube;
		int capacidad;
		int utils;
	public:
		NubeParticulas();
		NubeParticulas( int c );
		NubeParticulas(const NubeParticulas &otra);
		~NubeParticulas();
		void Copiar( const NubeParticulas &otra );
		int getCapacidad() const;
		int GetCardinal() const;
		void AgregaParticula(Particula nueva);
		void BorraParticula(int pos);
		Particula ObtieneParticula( int pos ) const;
		void Mover(int ancho, int alto);
		NubeParticulas& operator=( const NubeParticulas &otra );
		void Colisiones();
};

ostream& operator<<( ostream &flujo, NubeParticulas &cloud );

#endif
