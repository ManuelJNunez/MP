#include "particula.h"
#include <iostream>

using namespace std;

int main() {
    int nparticulas;
    Particula* p;
   
    cout << "Inserte número de partículas: ";
    cin >> nparticulas;

    p = new Particula[nparticulas];

    for( int i = 0; i< nparticulas; ++i ){
    	p[i].setRadio(20);
    }


    vredimensiona(800, 600);
   
	while (tecla() != ESCAPE) {
		borra();

		for( int i = 0; i < nparticulas; ++i ){
			for( int j = i+1; j < nparticulas ; ++j ){
				if(p[i].Colision(p[j])){
					p[i].Rebote( p[j] );
				}
			}
			p[i].mueve_particula();
			p[i].pinta_particula();
		}
		refresca();
		espera(25);
	}
	
	vcierra();
	delete []p;
	return 0;
}
