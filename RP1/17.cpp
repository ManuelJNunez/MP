#include <iostream>

using namespace std;

void Ordena( int **ptr, int izda, int dcha ){
	int pos_min, *aux;

	for( int i = izda; i < dcha; i++ ){
		pos_min = i;

		for( int j = i+1; j <= dcha; j++ ){
			if( *ptr[j] < *ptr[pos_min] )
				pos_min = j;
		}

			aux = ptr[i];
			ptr[i] = ptr[pos_min];
			ptr[pos_min] = aux;
	}

}

int main(){
	const int TOPE = 50, CENTINELA = -1;
	int *ptr[TOPE], vec[TOPE], utils, izda, dcha, num;

	utils = 0;

	cout << "Inserte el contenido del vector(-1 para terminar): ";
	cin >> num;

	while( num != CENTINELA ){
		vec[utils] = num;
		utils++;
		cin >> num;
	}

	for( int i = 0; i < utils; i++ )
		ptr[i] = &vec[i];

	do{
		cout << "Inserte el valor de la izquierda: ";
		cin >> izda;
	}while( izda < 0 );

	do{
		cout << "Inserte el valor de la derecha: ";
		cin >> dcha;
	}while( dcha > utils || dcha < izda );

	cout << endl << "Vector desordenado: ";

	for( int i = 0; i < utils; i++ )
		cout << *ptr[i] << " "; 

	Ordena(ptr, izda, dcha);

	cout << endl << "Vector ordenado: ";

	for( int i = 0; i < utils; i++ )
		cout << *ptr[i] << " ";

	cout << endl;

	return 0;
}