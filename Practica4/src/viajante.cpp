#include <string>
#include "viajante.h"

using namespace std;

void mejorTrayecto( const int m[][TAM],int mejortrayecto[], int tamanio, int comienzo ){
	bool ciudadvisitada[TAM] = {false};
	int min, proxciudad, contador, j;

	contador = 0;
	min = 1000;
	j = comienzo;
	ciudadvisitada[comienzo] = true;
	mejortrayecto[contador] = comienzo;

	while( contador < tamanio ){
		for( int i = 0; i < tamanio; i++ ){
			if( m[i][j] < min && m[i][j] != 0 && !ciudadvisitada[i] ){
				min = m[i][j];
				proxciudad = i;
			}
		}
		contador++;
		mejortrayecto[contador] = proxciudad;
		ciudadvisitada[proxciudad] = true;
		j = proxciudad;
		min = 1000;
	}

	mejortrayecto[contador] = mejortrayecto[0];

}

int costeTrayecto( const int m[][TAM], const int trayecto[], int utils ){
	int suma = 0;

	for( int i = 0; i < utils; i++ ){
		suma += m[trayecto[i+1]][trayecto[i]];
	}

	return suma;
}

int vecinoMasCercano( const int m[][TAM], int trayecto[], int utils, int& ciudad ){
	int min, mejortray, mejorprecio;

	min = 10000;

	for( int i = 0; i < utils; i++ ){
		mejorTrayecto(m, trayecto, utils, i);

		if( costeTrayecto(m, trayecto, utils) < min ){
			mejortray = i;
			min = costeTrayecto(m, trayecto, utils);
		}
	}

	mejorTrayecto( m, trayecto, utils, mejortray );
	ciudad = mejortray;

	return costeTrayecto(m, trayecto, utils);
}

string trayectoToString( const int trayecto[], int utils ){
	string tray = "";

	for( int i = 0; i <= utils; i++ ){
		tray += to_string(trayecto[i]);

		if( i < utils )
			tray += "-->";
	}

	return tray;
}