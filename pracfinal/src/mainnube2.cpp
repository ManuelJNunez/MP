#include <iostream>
#include <stdlib.h>
#include "nubeparticulas.h"

using namespace std;

int main(){
	srand(time(0));
	NubeParticulas base(5);

	NubeParticulas nuevo(base);
	nuevo.Mover(800,800);

	NubeParticulas otro;

	otro = nuevo;
	otro.Mover(800,800);

	cout << "\n Conjunto Inicial: " << endl;
	cout << base;
	cout << "\n Conjunto Movido 1: " << endl;
	cout << nuevo;
	cout << "\n Conjunto Movido 2: " << endl;
	cout << otro;
	cout << endl;

	vcierra();
	return 0;
}