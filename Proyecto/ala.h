#ifndef ALA_H_INCLUDED
#define ALA_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "aleron.h"
#include "conector.h"

class Ala : public Malla3D
{
   private:
    Aleron * aleron = new Aleron();
    Conector * conector = new Conector();
   public:
    Ala();
    void dibuja(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez);
} ;




#endif