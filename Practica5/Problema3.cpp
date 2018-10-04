#include <iostream>
#include <cmath>

using namespace std;

struct Punto2D{
	double x, y;
};

void BuscarCercanos( Punto2D *ptos, int nptos, int &p1, int &p2 ){
	double dmenor, dist;

	dmenor = 100000;

	for( int i = 0; i < nptos; i++ ){
		for( int j = i + 1; j < nptos; j++ ){
			dist = sqrt( pow( ( ptos[i].x - ptos[j].x ), 2) + pow( ( ptos[i].y - ptos[j].y ), 2) );

			if( dist < dmenor ){
				dmenor = dist;
				p1 = i;
				p2 = j;

			}
		}
	}
}

int main(){
	Punto2D *arrayptos;
	int nptos, posp1, posp2;
	double x, y;

	cout << "Indique el número de puntos: ";
	cin >> nptos;

	arrayptos = new Punto2D [nptos];

	cout << "Inserte los puntos:" << endl;

	for( int i = 0; i < nptos; i++ ){
		cin >> x >> y;

		arrayptos[i].x = x;
		arrayptos[i].y = y; 
	}

	BuscarCercanos( arrayptos, nptos, posp1, posp2 );

	cout << "----------------------" << endl << arrayptos[posp1].x << " " << arrayptos[posp1].y << endl;
	cout << arrayptos[posp2].x << " " << arrayptos[posp2].y << endl;


	delete [] arrayptos;

	return 0;
}