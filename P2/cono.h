#ifndef CONO_H_INCLUDED
#define CONO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

class Cono : public ObjRevolucion
{
    public:
        Cono(int num_vert_perfil = 2, int num_instancias_perf = 20, float h = 4.0, float r = 1.0) ;

    private:
        float altura,
              radio;

} ;


#endif
