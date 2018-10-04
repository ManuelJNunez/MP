#ifndef PARTICULA
#define PARTICULA
#include "miniwin.h"

using namespace miniwin;

class Particula{
   private:
      float x,y,radio;
      float dx, dy;
      Color c;

   public:
      Particula();
      Particula(float x, float y);
      Particula( float x, float y, Color c, float radio );
      void setCoords( float x, float y );
      void setX(float x);
      void setY(float y);
      void setDesplazamientos( float dx, float dy );
      void setColor( Color c );
      void setRadio( float radio );
      float getX() const;
      float getY() const;
      float getRadio() const;
      Color getColor() const;
      float getDX() const;
      float getDY() const;
      void pinta_particula() const;
      void mueve_particula();
      void mueve_particula(int ancho, int alto);
      float DistParticulas( Particula P2 ) const;
      void Rebote( Particula &otra );
      bool Colision( Particula P2 ) const;
      Particula& operator=( const Particula &otra );
};

#endif
