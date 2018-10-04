#include "particula.h"
#include "definiciones.h"
#include <stdlib.h>
#include <cmath>

/* "Color" es un tipo enumerado definido en Miniwin.h. 
Una variable de tipo Color puede tomar los siguientes valores:
NEGRO, ROJO, VERDE, AZUL, AMARILLO, MAGENTA, CYAN, BLANCO

*/

Particula::Particula(){
   x = rand() % MAX_X;
   y =  rand() % MAX_Y;
   dx =  1+rand() % MAX_VEL;
   dy =  1+rand() % MAX_VEL;
   c = Color(rand() % BLANCO);
   if( c == NEGRO )
   		c = BLANCO;
   radio = RADIO;
   }

Particula::Particula(float x, float y){
   this->x = x;
   this->y = y;
   dx = 1;
   dy =  1;
   c = ROJO;
}

Particula::Particula( float x, float y, Color c, float radio ){
   this->x = x;
   this->y = y;
   this->dx = dx;
   this->dy = dy;
   this->c = c;
   this->radio = radio;
}

void Particula::setCoords( float x, float y ){
   this->x = x;
   this->y = y;
}

void Particula::setX(float x){
	this->x = x;
}

void Particula::setY(float y){
	this->y = y;
}

void Particula::setDesplazamientos( float dx, float dy ){
   this->dx = dx;
   this->dy = dy;
}

void Particula::setColor( Color c ){
   this->c = c;
}

void Particula::setRadio( float radio ){
   this->radio = radio;
}

float Particula::getX() const{
   return x;
}

float Particula::getY() const{
   return y;
}

float Particula::getRadio() const{
	return radio;
}

Color Particula::getColor() const{
   return c;
}

float Particula::getDX() const{
	return dx;
}

float Particula::getDY() const{
	return dy;
}

void Particula::pinta_particula() const{
   color(c);
   circulo_lleno(x, y, radio);
}
      
void Particula::mueve_particula(){
   x += dx;
   y += dy;
   if (x > vancho() - radio) {
      dx = -dx;
      x = vancho() - radio;
   } 
   else if (x < radio) {
      dx = -dx;
      x = radio;
   } 
   else if (y > valto() - radio) {
      dy = -dy;
      y = valto() - radio;
   }
   else if (y < radio) {
      dy = -dy;
      y = radio;
   }
  //dy += 0.1;
}

void Particula::mueve_particula(int ancho, int alto){
   const float factor = 1;
   x += dx;
   y += dy;
   if (x > ancho - radio) {
      dx = -dx * factor;
      x = vancho() - radio;
   } 
   else if (x < radio) {
      dx = -dx * factor;
      x = RADIO;
   } 
   else if (y > alto - radio) {
      dy = -dy * factor;
      y = valto() - radio;
   }
   else if (y < radio) {
      dy = -dy * factor;
      y = RADIO;
   }
  //dy += 0.1;
}

float Particula::DistParticulas( Particula P2 ) const{
   float distancia;

   distancia = sqrt( pow(x-P2.x,2) + pow(y-P2.y,2) );

   distancia -= (P2.radio + radio);

   return distancia;
}

void Particula::Rebote( Particula &otra ){
   float factor, diffx, diffy, diffvy, diffvx;
   diffvx = dx - otra.dx;
   diffvy = dy - otra.dy;
   diffx = x - otra.x;
   diffy = y - otra.y;

   factor = (( diffvx * diffx ) + ( diffvy * diffy )) / ( pow(diffx, 2) + pow(diffy, 2) );

   this->dx -= factor * diffx;
   this->dy -= factor * diffy;

   otra.dx += factor * diffx;
   otra.dy += factor * diffy;

}

bool Particula::Colision( Particula P2 ) const{
   bool colisionado = false;

   if( this->DistParticulas(P2) < UMBRAL ){
      colisionado = true;
   }

   return colisionado;
}

Particula& Particula::operator=( const Particula &otra ){
	if( &otra != this ){
		this->x = otra.x;
		this->y = otra.y;
		this->radio = otra.radio;
    	this->dx = otra.dx;
    	this->dy = otra.dy;
    	this->c = otra.c;
	}

	return *this;
}

