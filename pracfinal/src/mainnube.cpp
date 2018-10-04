#include "nubeparticulas.h"
#include "definiciones.h"
#include <stdlib.h>

int main(){
	int ancho, alto, N;

	srand(time(0));
	ancho = 800;
	alto = 600;
	N = 10;
	vredimensiona(ancho, alto);

	NubeParticulas nube(N);
	Particula p;

	while( tecla() != ESCAPE ){
		nube.Colisiones();
		nube.Mover(ancho, alto);
		borra();
		for( int i = 0; i < N; ++i ){
			p = nube.ObtieneParticula(i);
			color(p.getColor());
			circulo_lleno( p.getX(), p.getY(), RADIO );
		}
		refresca();
		espera(15);
	}

	vcierra();
	return 0;
}