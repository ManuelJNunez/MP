#include <iostream>
#include <string>
#include "descifra.h"

using namespace std;

bool comienzaPalabra(const Vectores v, int j){
	bool comienza;
	comienza = false;

	if( j < v.utils )
		if( v.secuencia[j-1] == ' ' )
			comienza = true;

	return comienza;
}

bool terminaPalabra(const Vectores v, int j){
	bool termina;
	termina = false;

	if( j < v.utils )
		if( v.secuencia[j+1] == ' ' )
			termina = true;

	return termina;
}

Vectores descifra( const Vectores codificada ){
	Vectores descifrada;
	int siguiente, i;
	bool empieza;

	descifrada.utils = i = 0;

	empieza = true;

	while (i < codificada.utils){
        siguiente = i+1;
               
        if ( codificada.secuencia[i] != ' ' ){
            if ( empieza ||  siguiente < codificada.utils && terminaPalabra(codificada, i) ){
                descifrada.secuencia[descifrada.utils] = codificada.secuencia[i];
                descifrada.utils++;
            }
            
            empieza = false;
         }else
            empieza = true;
         
        i = siguiente;
      }

	return descifrada;	
}

string toString(const Vectores v){
	string secuencia;

	secuencia = "";

	for(int i = 0; i <= v.utils; i++)
		secuencia += v.secuencia[i];

	return secuencia;
}