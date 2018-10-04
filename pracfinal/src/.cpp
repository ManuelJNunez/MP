#include "particula.h"
#include "definiciones.h"
#include <stdlib.h>
#include <cmath>

/* "Color" es un tipo enumerado definido en Miniwin.h. 
Una variable de tipo Color puede tomar los siguientes valores:
NEGRO, ROJO, VERDE, AZUL, AMARILLO, MAGENTA, CYAN, BLANCO

*/

Particula::Particula(){
   setCoords( rand() % MAX_X, rand() % MAX_Y );
   setDesplazamientos( 1+rand() % MAX_VEL, 1+rand() % MAX_VEL );
   c = Color(rand() % BLANCO );
   }

Particula::Particula(float x, float y){
   setCoords( x, y );
   setDesplazamientos( 1, 1 );
   setColor( ROJO );
}

Particula::Particula( float x, float y, Color c, float radio ){
   setCoords(x,y);
   setDesplazamientos(dx, dy);
   setColor(c);
   setRadio(radio);
   colddown = 0;
   visible = true;
}

void Particula::setCoords( float x, float y ){
   this->x = x;
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

void Particula::setVisibilidad( bool visible ){
   this->visible = visible;
}

float Particula::getX(){
   return x;
}

float Particula::getY(){
   return y;
}

Color Particula::getColor(){
   return c;
}

bool Particula::getVisibilidad(){
   return visible;
}

void Particula::pinta_particula(){
   color(c);
   circulo_lleno(x, y, radio);
}

void Particula::pinta_particula(Color secundario, float radsecun){
   color(c);
   circulo_lleno(x, y, radio);
   color(secundario);
   circulo_lleno(x, y, radsecun);

}
      
void Particula::mueve_particula(){
   const float factor = 1;
   x += dx;
   y += dy;
   if (x > vancho() - RADIO) {
      dx = -dx * factor;
      x = vancho() - RADIO;
   } 
   else if (x < RADIO) {
      dx = -dx * factor;
      x = RADIO;
   } 
   else if (y > valto() - RADIO) {
      dy = -dy * factor;
      y = valto() - RADIO;
   }
   else if (y < RADIO) {
      dy = -dy * factor;
      y = RADIO;
   }
  //dy += 0.1;
}

void Particula::mueve_particula(int ancho, int alto){
   const float factor = 1;
   x += dx;
   y += dy;
   if (x > ancho - RADIO) {
      dx = -dx * factor;
      x = vancho() - RADIO;
   } 
   else if (x < RADIO) {
      dx = -dx * factor;
      x = RADIO;
   } 
   else if (y > alto - RADIO) {
      dy = -dy * factor;
      y = valto() - RADIO;
   }
   else if (y < RADIO) {
      dy = -dy * factor;
      y = RADIO;
   }
  //dy += 0.1;
}

void Particula::mueve_particula2(){
   x += dx;
   y += dy;

   if (x > vancho() - radio )
      visible = false;
   else if (x < radio)
      visible = false;
   else if (y > valto() - radio)
      visible = false;
   else if (y < radio)
      visible = false;
}

void Particula::MoverRaton(){
   if( raton_x() < 470 && raton_x() > 30 )
      x = raton_x();
   else if( raton_x() >= 470 )
      x = 470;
   else if (raton_x() <= 30 )
      x = 30;
}

float Particula::DistParticulas( Particula P2 ){
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

   dx -= factor * diffx;
   dy -= factor * diffy;
   otra.dx += factor * diffx;
   otra.dy += factor * diffy;

}

void Particula::GenerarParticula( float x, float y, float dx, float dy ){
   this->x = x;
   this->y = y;
   this->dx = dx;
   this->dy = dy;
   visible = true;
}

bool Particula::Ready4Shoot(){
   bool disparar;

   disparar = false;
   colddown += WAIT;

   if( colddown == 500 ){
      disparar = true;
      colddown = 0;
   }

   return disparar;
}

bool Colision( Particula P1 ,Particula P2 ){
   bool colisionado = false;

   if( P1.DistParticulas(P2) < UMBRAL ){
      colisionado = true;
   }

   return colisionado;
}

