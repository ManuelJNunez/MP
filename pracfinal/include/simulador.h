#ifndef SIMULADOR
#define SIMULADOR
#include "nubeparticulas.h"

class Simulador{
	private:
		NubeParticulas mi_nube;
		int nro_p;
		int ancho, alto;
	public:
		Simulador( int ancho, int alto, int nro_p );
		~Simulador();
		void Mover();
		void Pintar();
        void GestionaColisiones();
};

#endif
