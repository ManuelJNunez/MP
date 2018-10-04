#include <string>
#include "tiraLed.h"

using namespace std;

void encenderLed( bool tira[], int tamtira, int pos ){
	if( pos <= tamtira )
		tira[pos] = true;
}

void apagarLed( bool tira[], int tamtira, int pos ){
	if( pos <= tamtira )
		tira[pos] = false;
}

void cambiaLeds( int pos[], int tamanio, bool tira[] ){
	for( int i = 0; i <= tamanio; i++ ){
		if ( !tira[pos[i]] )
			tira[pos[i]] = true;
		else
			tira[pos[i]] = false;
	}
}

string toString( const bool tira[], int tamtira ){
	string tiraleds;

	tiraleds = "";

	for( int i = 0; i <= tamtira; i++ )
		tiraleds += tira[i];

	return tiraleds;
}