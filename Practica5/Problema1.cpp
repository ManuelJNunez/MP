#include <iostream>
#include <stdlib.h>
using namespace std;

void Redimensiona ( int * & p, const int tipo, int & cap ){
	const int TAM_BLOQUE = 5;
	int new_cap;

	switch( tipo ){
		case 1:
			cap++;
			break;
		case 2:
			cap += TAM_BLOQUE;
			break;
		case 3:
			cap *= 2;
			break;
		default:
			exit(1);
	}

	int *p_newtam = new int [new_cap];

	for( int i = 0; i < cap; i++ ){
		p_newtam[i] = p[i];
	}

	delete []p;
	p = p_newtam;
	cap = new_cap;

}

int main(){
	const int TAM = 5, FIN = -1;
	int tipo, *ptr = 0, opt, utils = 0, utilizables, num;

	utilizables = TAM;
	ptr = new int [TAM];

	cout << "Inserte valores (-1 para terminar): ";

	while( num != FIN ){
		if( utils == utilizables ){
			do{
				cout << "¿Cómo quiere redimensionar el vector?" << endl;
				cout << "1- Una casilla" << endl;
				cout  << "2- En un bloque de tamaño 5" << endl;
				cout << "3- Duplicar su tamaño" << endl;
				cout << endl << "Inserte una opcion: ";
				cin >> opt;
			}while( opt < 0 || opt > 3 );

			Redimensiona(ptr, opt, utilizables);

			do{
				cout << endl << "¿Quiere ver el vector (0 o 1)? ";
				cin >> opt;
			}while( opt < 0 || opt > 1 );

				if( opt == 1 ){
					cout << "Vector: ";
					for( int i = 0; i < utils; i++ )
						cout << ptr[i] << " ";
				}

			cout << endl << "Inserte valores (-1 para terminar): ";
		}
		cin >> num;
		ptr[utils] = num;
		utils++;
	}

	delete []ptr;

	return 0;
}