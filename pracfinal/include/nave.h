#ifndef NAVE
#define NAVE
#include "particula.h"

using namespace miniwin;

class Nave{
	private:
		Particula nave;
		bool visible;
		int vida, colddown, punt, tiempomuerto, trefrescado;
	public:
		Nave();
    	Nave(float x, float y, Color c, float radio);
		void setVisibilidad( bool visible );
		void setColor( Color c );
		void setRadio( float r );
		void setCoords(float x, float y);
		void setVelocidades( float vx, float vy );
		void setVida(int vida);
		void setTRefrescado(int tiempo);
		bool getVisibilidad() const;
		float getX() const;
		float getY() const;
		int getVida() const;
		void pinta();
		void pinta(Color secundario, float radsecun);
		void mueve();
		void GeneraDisparo( float x, float y, float vx, float vy );
		void MoverRaton();
		bool Ready4Shoot();
    	void ChequeaRespawn(float &tspawn);
    	bool Impacto( Nave otra );
};

#endif