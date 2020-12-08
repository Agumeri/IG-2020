// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED

#include "aux.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 8 vertices y 6 caras)

class Cubo : public Malla3D
{
   public:
      Cubo(float lado=1) ;
      // void resize_v(int n);
      // void resize_f(int n);
      // void set_v(int num_v, float _x, float _y, float _z);
      // void set_f(int num_f, int v_x, int v_y, int v_z);
};




#endif
