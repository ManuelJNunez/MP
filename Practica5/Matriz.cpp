#include <iostream>

using namespace std;

void Limpiar( char **m, int tam ){
	for( int i = 0; i < tam; ++i )
		for( int j = 0; j < tam; ++j )
			m[i][j] = '.';
}

void Dibujar( char **m, int x, int y, int l ){
	for( int i = y; i < ( y + l ); ++i )
		for( int j = x; j < ( x + l ); ++j )
			m[i][j] = '*';
}

void Rotar( char **m, char **mnew, int tam ){
	int newcol, newfil;

	for( int i = 0; i < tam; ++i ){
		newcol = tam - 1;

		for( int j = 0; j < tam; ++j ){
			mnew[newcol][i] = m[i][j];
			newcol--;
		}
	}
}

void Imprimir( char **m, int tam ){
	for( int i = 0; i < tam; ++i ){
		for( int j = 0; j < tam; ++j )
			cout << m[i][j] << " ";

		cout << endl;
	}
}

int main(){
	char **a, **b;
	int n;

	cout << "Inserte el tamaño del lienzo: ";
	cin >> n;

	a = new char*[n];

	for( int i = 0; i < n; ++i )
		a[i] = new char[n];

	b = new char*[n];

	for( int i = 0; i < n; ++i )
		b[i] = new char[n];

	cout << endl  << "Dibujo de una flecha: " << endl;
	
	Limpiar( a, n );
	Dibujar( a, 1, 1, 2 );
	Dibujar( a, 2, 1, 2 );
	Dibujar( a, 2, 0, 1 );
	Dibujar( a, 0, 2, 1 );
	Dibujar( a, 4, 2, 1 );
	Dibujar( a, 2, 3, 1 );
	Dibujar( a, 2, 4, 1 );
	Imprimir( a, n );

	cout << endl << "Flecha rotada: " << endl;
	Rotar( a, b, n );
	Imprimir( b, n );

	cout << endl << "Lienzo limpio: " << endl;
	Limpiar( a, n );
	Imprimir( a, n );

	for( int i = 0; i < n; ++i )
		delete [] a[i];
	delete []a;

	for( int i = 0; i < n; ++i )
		delete [] b[i];
	delete []b;

	return 0;
}