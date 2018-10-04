#include <string>
#include "miniwin.h"

using namespace std;
using namespace miniwin;

void Gameover( int puntuacion, int mejorpuntuacion ){
	string gameover = "GAME OVER", punt, mejorpunt;
	punt = "Obtuviste: " + to_string(puntuacion) + " puntos.";
	mejorpunt = "Mejor puntuacion: " + to_string(mejorpuntuacion);
	borra();
	color(ROJO);
	texto( 210, 400, gameover );
	texto( 180, 440, punt );
	texto( 180, 460, mejorpunt );

	refresca();
	espera(3000);

	borra();
}

void Menu( string opt1, int &opt ){
	vredimensiona(400, 400);
	string nombre = "SALVAR LA GALAXIA", opt2 = "Salir";
	bool elegido = false, pulsaizq, pulsadcho;
	float x, y;

	opt = 2;

	while( tecla() != ESCAPE && !elegido ){
		borra();
		color(VERDE);
		texto( 145, 100, nombre );
		raton(x, y);
		raton_botones(pulsaizq, pulsadcho);

		if( (x >= 145 && x <= 245) && (y >= 135 && y <= 158) ){
			color(CYAN);
			if(pulsaizq){
				opt = 1;
				elegido = true;
			}
		}
		else
			color(AZUL);

		rectangulo_lleno( 145, 135, 245, 158 );

		if( (x >= 145 && x <= 245) && (y >= 165 && y <= 188) ){
			color(CYAN);
			if(pulsaizq){
				elegido = true;
			}
		}
		else
			color(AZUL);
		rectangulo_lleno( 145, 165, 245, 188 );

		color(BLANCO);
		texto( 155, 150, opt1 );
		texto( 180, 180, opt2 );

		refresca();
		espera(25);
	}
}