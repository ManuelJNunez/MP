#ifndef TIRALED
#define TIRALED
#include <string>

using namespace std;

const int TAM = 100;

void encenderLed( bool tira[], int tamtira, int pos );
void apagarLed( bool tira[], int tamtira, int pos );
void cambiaLeds( int pos[], int tamanio, bool tira[] );
string toString( const bool tira[], int tamtira );

#endif