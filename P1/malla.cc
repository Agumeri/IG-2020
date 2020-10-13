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

  // indicamos el color con el que se van a pintar las caras
//   glColorPointer(3, GL_FLOAT, 0, color);

  // visualizar, indicando: tipo de primitiva, numero de indices,
  // tipo de los indices, y direccion de la tabla de indices
  glDrawElements( GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data());

  // deshabilitar array de vertices
  glDisableClientState( GL_VERTEX_ARRAY );
  
}
// -----------------------------------------------------------------------------
// Funcion utilizada para producir un identificador de VBO

GLuint Malla3D::CrearVBO( GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram){
   GLuint id_vbo; // resultado: identificador de VBO

   glGenBuffers(1, & id_vbo); // crear nuevo VBO, obtener identificador (nunca 0)

   glBindBuffer(tipo_vbo, id_vbo); // activar el VBO usando su identificador

   // esta instruccion hace la transferencia de datos desde RAM hacia GPU
   glBufferData(tipo_vbo, tamanio_bytes, puntero_ram, GL_STATIC_DRAW);

   glBindBuffer(tipo_vbo, 0); // desactivación del VBO (activar 0);

   return id_vbo; // devolver el identificador resultado
}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

void Malla3D::draw_ModoDiferido()
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....

   // creamos los identificadores del VBO para las caras y para los vertices
   if (id_vbo_ver == 0 && id_vbo_tri == 0)
   {
      id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, 3 * sizeof(float) * v.size(), v.data());       // id para los vertices
      id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(int) * f.size(), f.data()); // id para las caras
   }

   // una vez creados, procedemos a visualizar la malla
   
   //especificar localización y formato de la tabla de vértices, habilitar tabla
   // activar VBO de vertices
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);

   // especifica formato y ofsset (=0)
   glVertexPointer(3, GL_FLOAT, 0, 0);

   // desactivar VBO de vertices
   glBindBuffer(GL_ARRAY_BUFFER, 0);

   // habilitar tabla de vertices
   glEnableClientState(GL_VERTEX_ARRAY);

   // visualizar triangulos con glDrawElements (puntero a tabla == 0)
   // activar VBO de triangulos
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);

   // dibujamos los triangulos
   glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);

   // desactivar VBO de triangulos
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   // desactivar uso de array de vertices
   glDisableClientState(GL_VERTEX_ARRAY);
}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw()
{
   // completar .....(práctica 1)
   // this->draw_ModoInmediato();
   this->draw_ModoDiferido();
}

