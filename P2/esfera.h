#ifndef ESFERA_H_INCLUDED
#define ESFERA_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

class Esfera : public ObjRevolucion
{
    public:
        Esfera(int num_vert_perfil = 10, int num_instancias_perf = 20, float r = 1.0);

    private:
        float radio;

} ;


#endif
