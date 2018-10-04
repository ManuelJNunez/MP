#include <iostream>

using namespace std;

int *PosMayor( int *pv, int izda, int dcha ){
	int *ptr, mayor;

	mayor = 0;

	for( int i = izda; i <= dcha; i++ )
		if( *(pv+i) > mayor ){
			mayor = *(pv+i);
			ptr = &(*(pv+i));
		}

	return ptr;
}

int main(){
	const int TOPE = 100, CENTINELA = -1;
	int *ptrmayor, vector[TOPE], dcha, izda, num, utils;

	utils = 0;

	cout << "Inserte los elementos del vector (-1 para terminar): ";
	cin >> num;

	while( num != CENTINELA ){
		vector[utils] = num;
		utils++;
		cin >> num;
	}

	do{
		cout << "Inserte el valor de la izquierda: ";
		cin >> izda;
	}while( izda < 0 );

	do{
		cout << "Inserte el valor de la derecha: ";
		cin >> dcha;
	}while( dcha > utils || dcha < izda );

	ptrmayor = PosMayor( vector, izda, dcha );

	cout << "El elemento mayor es " << *ptrmayor << endl;

	return 0;
}