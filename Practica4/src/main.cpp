#include <iostream>
#include "viajante.h"

using namespace std;

int main(){
	int viajes[TAM][TAM], masbarato[TAM], nciudades, inicio, mejorprecio;

	do{
		cout << "Inserte el numero de ciudades: ";
		cin >> nciudades;
	}while( nciudades > TAM );

	cout << endl << "Inserte los datos de ciudades:\n";

	for( int j = 0; j < nciudades; j++ )
		for( int i = 0; i < nciudades; i++)
			cin >> viajes[i][j];

	mejorprecio = vecinoMasCercano( viajes, masbarato, nciudades, inicio );

	cout << endl << "Trayecto más barato: " << trayectoToString( masbarato, nciudades ) << endl;
	cout << "Coste total: " <<  mejorprecio << endl;

	return 0;
}