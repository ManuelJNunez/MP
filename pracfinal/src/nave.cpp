#include "nave.h"
#include <stdlib.h>
#include "definiciones.h"

using namespace miniwin;
Nave::Nave(){
   visible = true;
   tiempomuerto = 0;
   colddown = 0;
   vida = 100;
}

Nave::Nave( float x, float y, Color c, float radio ): nave( x, y, c, radio ){
   visible = true;
   tiempomuerto = colddown = 0;
   vida = 100;
}

void Nave::setVisibilidad( bool visible ){
   this->visible = visible;
}

void Nave::setColor( Color c ){
   nave.setColor(c);
}

void Nave::setRadio( float r ){
   nave.setRadio(r);
}

void Nave::setCoords(float x, float y){
   nave.setCoords(x, y);
}

void Nave::setVelocidades( float vx, float vy ){
   nave.setDesplazamientos(vx, vy);
}

void Nave::setVida( int life ){
   vida = life;
}

void Nave::setTRefrescado( int tiempo ){
	trefrescado= tiempo;
}

bool Nave::getVisibilidad() const{
   return visible;
}

float Nave::getX() const{
   return nave.getX();
}

float Nave::getY() const{
   return nave.getY();
}

int Nave::getVida() const{
   return vida;
}

void Nave::pinta(){
   nave.pinta_particula();
}

void Nave::pinta(Color secundario, float radsecun){
   color(nave.getColor());
   circulo_lleno( nave.getX(), nave.getY(), nave.getRadio());
   color(secundario);
   circulo_lleno(nave.getX(), nave.getY(), radsecun);
}

void Nave::mueve(){
   nave.setX(nave.getX() + nave.getDX());
   nave.setY(nave.getY() + nave.getDY());

   if (nave.getX() > vancho() - nave.getRadio() ){
      visible = false;
      vida = 100 + rand() % 100;
   }
   else if (nave.getX() < nave.getRadio()){
      vida = 100 + rand() % 100;
      visible = false;
   }
   else if (nave.getY() > valto() - nave.getRadio())
      visible = false;
   else if (nave.getY() < nave.getRadio())
      visible = false;
}

void Nave::GeneraDisparo(float x, float y, float vx, float vy){
   visible = true;
   nave.setCoords(x, y);
   nave.setDesplazamientos(vx, vy);
}

void Nave::MoverRaton(){
   if( raton_x() < 470 && raton_x() > 30 )
      nave.setX(raton_x());
   else if( raton_x() >= 470 )
      nave.setX(470);
   else if (raton_x() <= 30 )
      nave.setX(30);
}

bool Nave::Ready4Shoot(){
   bool disparar;

   disparar = false;
   colddown += WAIT;

   if( colddown > trefrescado ){
      disparar = true;
      colddown = 0;
   }

   return disparar;
}

void Nave::ChequeaRespawn(float &tspawn){
   const float FACTOR = 0.87;
   bool aparecido;

   aparecido = false;

   if( !visible ){
      tiempomuerto += WAIT;

      if( tiempomuerto >= tspawn ){
         this->setCoords( 30 + rand() % 470, 30 );
         visible = aparecido = true;
         tiempomuerto = 0;
      }

      if( !aparecido && tspawn > 2000 )
         tspawn *= FACTOR;
   }
}

bool Nave::Impacto( Nave otra ){
   return nave.Colision(otra.nave);
}