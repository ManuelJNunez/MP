#include "simulador.h"
#include <stdlib.h>

int main(){
	int ancho = 400, alto = 600, particulas = 5;
	srand(time(0));
	Simulador gestor(ancho, alto, particulas);

	while( tecla() != ESCAPE ){
		gestor.GestionaColisiones();
		gestor.Mover();
		gestor.Pintar();
		espera(15);
	}

	return 0;
}