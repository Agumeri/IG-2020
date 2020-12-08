#ifndef CONECTOR_H_INCLUDED
#define CONECTOR_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"

class Conector : public Malla3D
{
   private:
    Esfera * e1 = new Esfera(10,20,4,true,true);
    Esfera * e2 = new Esfera(10,20,4,true,true);
    Esfera * e3 = new Esfera(10,20,4,true,true);
    Cilindro * c1 = new Cilindro(2,20,20,4,true,true);
    Cilindro * c2 = new Cilindro(2,20,20,4,true,true);

   public:
    Conector();
    void dibuja(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez);
} ;




#endif
