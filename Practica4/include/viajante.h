#ifndef VIAJANTE
#define VIAJANTE
#include <string>

using namespace std;

const int TAM = 1000;

void mejorTrayecto( const int m[][TAM],int mejortrayecto[], int tamanio, int comienzo );
int costeTrayecto( const int m[][TAM], const int trayecto[], int utils );
int vecinoMasCercano( const int m[][TAM], int trayecto[], int utils, int& ciudad );
string trayectoToString( const int trayecto[], int utils );

#endif