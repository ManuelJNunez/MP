#include <iostream>
#include "descifra.h"
#include "tiraLed.h"

using namespace std;

int main(){
	Vectores mensaje, descifrado;
	char letra;

	cout << "Ingrese la frase. @ para terminar: ";
	letra = cin.get();

	while (letra != '@'){
		mensaje.secuencia[mensaje.utils] = letra;
		mensaje.utils++;
		letra = cin.get();
	}

	cout << "Mensaje cifrado: ";

	for(int i = 0; i < mensaje.utils; i++)
		cout << mensaje.secuencia[i];
	
	cout << endl;

	descifrado = descifra(mensaje);

	cout << "Mensaje descifrado: " << toString(descifrado) << endl << endl;

	bool tira[TAM];
	int utils_tira;

	do{
		cout << "Introduzca el número de LEDS de la tira: ";
		cin >> utils_tira;
	}while(utils_tira > TAM);

	cout << "Muy bien, voy a apagar la tira entera: ";

	for( int i = 0; i < utils_tira; i++ ){
		apagarLed(tira, utils_tira, i );
		cout << tira[i];
	}

	cout << endl;

	cout << "Ahora encenderé los LEDS de la posiciones pares: ";

	for(int i = 0; i < utils_tira; i++){
		if( i%2 == 0 )
			encenderLed(tira, utils_tira, i);

		cout << tira[i];
	}

	cout << endl;

	cout << "Ahora apagaré los LEDS de las posiciones pares y encenderé los de las posiciones impares: ";

	for(int i = 0; i < utils_tira; i++){
		if(i%2 == 0)
			apagarLed(tira, utils_tira, i);
		else
			encenderLed(tira, utils_tira, i);

		cout << tira[i];
	}

	cout << endl;

	return 0;
}