#ifndef ALA_H_INCLUDED
#define ALA_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "aleron.h"
#include "conector_superior.h"
#include "conector_inferior.h"

class Ala : public Malla3D
{
   private:
    Aleron * aleron = new Aleron();
    // Conector * conector = new Conector();
    ConectorSuperior * con_sup = new ConectorSuperior();
    ConectorInferior * con_inf = new ConectorInferior();
   public:
    Ala();
    void dibuja(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez);
} ;




#endif