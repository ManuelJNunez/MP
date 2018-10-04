#ifndef DESCIFRA
#define DESCIFRA
#include <string>

using namespace std;

struct Vectores
{
	static const int TAM = 100;
	char secuencia[TAM];
	int utils;
};

bool comienzaPalabra(const Vectores v, int j);
bool terminaPalabra(const Vectores v, int j);
Vectores descifra( const Vectores codificada );
string toString(const Vectores v);

#endif