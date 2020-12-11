#ifndef TIEFIGHTER_H_INCLUDED
#define TIEFIGHTER_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "ala.h"
#include "esfera.h"

class TieFighter : public Malla3D
{
   private:
    Ala * ala_derecha = new Ala();
    Ala * ala_izquierda = new Ala();
    Esfera * cabina = new Esfera(10,20,4,true,true);
   public:
    TieFighter();
    void dibuja(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez);
} ;




#endif