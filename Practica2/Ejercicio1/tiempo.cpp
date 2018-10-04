#include <iostream>

using namespace std;

const int H_S = 3600, M_S = 60;

struct Instante
{
	int hora, minuto, segundo;
};

int convertirASegundos(Instante inst){
	return ( inst.hora * H_S ) + ( inst.minuto * M_S ) + inst.segundo;
}

bool esPosterior(Instante inst1, Instante inst2){
	return convertirASegundos(inst1) > convertirASegundos(inst2);
}

Instante obtenerNuevoTiempo(Instante inst, int suma){
	Instante nuevo;
	inst.segundo = convertirASegundos(inst) + suma;


	nuevo.hora = inst.segundo / H_S;
	nuevo.minuto = ( inst.segundo - (nuevo.hora * 3600) ) / M_S;
	nuevo.segundo = inst.segundo - ( nuevo.minuto * 60 + nuevo.hora * 3600 );

	return nuevo;
}

int main(){
	int hora, minuto, segundo, mayor;

	mayor = 0;

	do{
		cout << "Inserte un instante (hora minuto segundo): ";
		cin >> hora >> minuto >> segundo;
	}while( hora > 23 || minuto > 59 || segundo > 59 || hora < 0 || minuto < 0 || segundo < 0 );

	Instante uno = {hora, minuto, segundo};

	do{
		cout << "Inserte otro instante (hora minuto segundo): ";
		cin >> hora >> minuto >> segundo;
	}while( hora > 23 || minuto > 59 || segundo > 59 || hora < 0 || minuto < 0 || segundo < 0 );

	Instante dos = {hora, minuto, segundo};

	cout << "El instante 1 tiene " << convertirASegundos(uno) << " segundos y el 2 tiene " << convertirASegundos(dos) << " segundos. ";

	if( esPosterior(uno, dos) )
		mayor = 1;
	else 
		mayor = 2;

	cout << "Por tanto el instante " << mayor << " es el posterior." << endl;

	do{
		cout << "Inserte un ultimo instante (hora minuto segundo): ";
		cin >> hora >> minuto >> segundo;
	}while( hora > 23 || minuto > 59 || segundo > 59 || hora < 0 || minuto < 0 || segundo < 0 );

	Instante tres = {hora, minuto, segundo};

	cout << "Inserte los segundos que quiere sumarle: ";
	cin >> segundo;

	Instante cuatro = obtenerNuevoTiempo(tres, segundo);

	cout << "El nuevo instante es: " << cuatro.hora << ":" << cuatro.minuto << ":" << cuatro.segundo << endl;

	return 0;
}