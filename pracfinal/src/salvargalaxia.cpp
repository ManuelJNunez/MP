#include "nave.h"
#include "funciones.h"
#include "definiciones.h"
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main(){
	srand((unsigned) time(NULL));
	Nave player(XINICIO, YINICIO, CYAN, RNAVE);
	Nave enemy1;
	Nave proyplayer[TAM];
	Nave proyenemy[TAM];
	bool encontrado1, encontrado2, enemigovisible, playervisible, salir;
	float tiempospawn;
	int puntuacion, optelegida, mejorpuntuacion;
	string opt = "Vamos a jugar";

	mejorpuntuacion = 0;

	Menu(opt, optelegida);
	opt = "Volver a jugar";

	while( optelegida != 2 ){
		puntuacion = optelegida = 0;
		tiempospawn = 1000;
		player.setTRefrescado(1000);
		enemy1.setTRefrescado(200);
		enemy1.setCoords( 30 + rand() % 440, 30 );
		enemy1.setColor(ROJO);
		enemy1.setRadio(RNAVE);
		enemy1.setVisibilidad(false);
		enemy1.setVelocidades(0, VNAVE);
		encontrado1 = encontrado2 = salir = false;

		for( int i = 0; i < TAM; ++i ){
			proyplayer[i].setColor(VERDE);
			proyplayer[i].setRadio(RPROYECTIL);
			proyplayer[i].setVisibilidad(false);
			proyenemy[i].setColor(AMARILLO);
			proyenemy[i].setRadio(RPROYECTIL);
			proyenemy[i].setVisibilidad(false);
		}
		vredimensiona(500, 800);

		while( tecla() != ESCAPE && !salir ){
			borra();

			enemigovisible = enemy1.getVisibilidad();
			playervisible = player.getVisibilidad();

			enemy1.ChequeaRespawn(tiempospawn);

			if( playervisible ){
				player.MoverRaton();
				player.pinta(BLANCO, RINTERIOR);

				if( player.Ready4Shoot() ){
					for( int i = 0; i < TAM && !encontrado1; ++i ){
						if( !proyplayer[i].getVisibilidad() ){
							encontrado1 = true;
							proyplayer[i].GeneraDisparo( player.getX(), player.getY() - RNAVE, 0, -VPROYECTIL);
						}
					}
				}
			}

			for( int i = 0; i < TAM; ++i ){
				if( proyplayer[i].getVisibilidad() ){
					proyplayer[i].mueve();
					proyplayer[i].pinta();
				}
			}

			for( int i = 0; i < TAM; ++i ){
				if( proyenemy[i].getVisibilidad() ){
					proyenemy[i].mueve();
					proyenemy[i].pinta();
				}
			}


			if( enemigovisible ){
				enemy1.mueve();
				enemy1.pinta(BLANCO, 15);

				if( enemy1.Ready4Shoot() ){
					for( int i = 0; i < TAM && !encontrado2; ++i ){
						if( !proyenemy[i].getVisibilidad() ){
							encontrado2 = true;
							proyenemy[i].GeneraDisparo( enemy1.getX(), enemy1.getY() + RNAVE, (rand() % 41) -20, VPROYENEMY);
						}
					}
				}

				for(int i = 0; i < TAM; ++i){
					if( proyplayer[i].getVisibilidad() )
						if( proyplayer[i].Impacto(enemy1) ){
							enemy1.setVida(enemy1.getVida() - DANO);
							proyplayer[i].setVisibilidad(false);
							puntuacion += PUNTOSPORIMPACTO;
							if( enemy1.getVida() <= 0 ){
								puntuacion += PUNTOSPORBAJA;
								enemy1.setVisibilidad(false);
								enemy1.setVida( MAXVIDA );
							}
						}
				}	

				if( player.Impacto(enemy1) ){
					enemy1.setVisibilidad(false);
					salir = true;
				}
			}

			for( int i = 0; i < TAM; ++i ){
				if( proyenemy[i].getVisibilidad() )
					if( proyenemy[i].Impacto(player) )
						salir = true;
			}

			refresca();
			espera(WAIT);
			encontrado1 = encontrado2 = false;
		}
		if( puntuacion > mejorpuntuacion )
			mejorpuntuacion = puntuacion;

		Gameover(puntuacion, mejorpuntuacion);
		Menu(opt, optelegida);
	}

	vcierra();
	return 0;
}