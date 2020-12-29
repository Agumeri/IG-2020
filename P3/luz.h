#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

#include "aux.h"

class Luz
{
    public:
        void activar();

    protected:
        Tupla4f posicion;
        GLenum id;
        Tupla4f colorAmbiente,
                colorDifuso,
                colorEspecular;
};

#endif