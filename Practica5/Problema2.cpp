#include <iostream>

using namespace std;

void Redimensiona ( int * & p, int & cap ){
	int *p_newtam = new int [cap];

	for( int i = 0; i < cap; i++ ){
		p_newtam[i] = p[i];
	}

	delete []p;
	p = p_newtam;
}

void ObtenerSegmento( const int *v, int utils,int * &posimp, int &nimpares ){
	for( int i = 0; i < utils; i++ )
		if( v[i] % 2 != 0 ){
			posimp[nimpares] = i;
			nimpares++;
		}

	Redimensiona( posimp, nimpares );
}

int main(){
	const int TAM = 50, FIN = -1;
	int *v = 0, utils, *impares = 0, nimpares, num;

	v = new int [TAM];
	impares = new int [TAM];
	nimpares = utils = 0;

	cout << "Inserte valores al vector (-1 para terminar): ";
	cin >> num;

	while( num != FIN ){
		v[utils] = num;
		utils++;
		cin >> num;
	}

	ObtenerSegmento( v, utils, impares, nimpares );

	cout << "Posiciones de los impares: ";

	for( int i = 0; i < nimpares; i++ )
		cout << impares[i] << " ";

	cout << endl;

	delete [] v;
	delete [] impares;

	return 0;
}