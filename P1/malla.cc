#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato()
{  
  // habilitar uso de un array de vertices
  glEnableClientState( GL_VERTEX_ARRAY );
  
  // indicar el formato y la direccion de memoria del array de vertices
  // (son tuplas de 3 valores float, sin espacio entre ellas)
  glVertexPointer( 3, GL_FLOAT, 0, v.data() );

  // visualizar, indicando: tipo de primitiva, numero de indices,
  // tipo de los indices, y direccion de la tabla de indices
  glDrawElements( GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data());

  // deshabilitar array de vertices
  glDisableClientState( GL_VERTEX_ARRAY );
  
}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

void Malla3D::draw_ModoDiferido()
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....


}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw()
{
   // completar .....(práctica 1)
   this->draw_ModoInmediato();
}

