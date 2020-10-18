#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************
// Visualizacion en modo ajedrez 
void Malla3D::draw_ModoAjedrez(){
   // Utilizamos auxiliares para pintar las caras impares y pares
   std::vector<Tupla3i> f_aux, f_a, f_b;
   f_aux = f;

   // Distribuimos los indices de las caras en dos variables
   for(int i=0; i<f_aux.size(); i+=2){
      f_a.push_back(f_aux[i]);
      f_b.push_back(f_aux[i+1]);
   }

   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);

   glColorPointer(3, GL_FLOAT, 0, color_solid_inm);
   glVertexPointer( 3, GL_FLOAT, 0, v.data() );
   glDrawElements( GL_TRIANGLES, f_a.size()*3, GL_UNSIGNED_INT, f_a.data());

   glColorPointer(3, GL_FLOAT, 0, color_solid_dif);
   glVertexPointer( 3, GL_FLOAT, 0, v.data() );
   glDrawElements( GL_TRIANGLES, f_b.size()*3, GL_UNSIGNED_INT, f_b.data());

   // deshabilitar array de vertices
   glDisableClientState( GL_VERTEX_ARRAY );
   glDisableClientState( GL_COLOR_ARRAY );

}


// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato(std::string color_pintar)
{ 
  // habilitar uso de un array de vertices
  glEnableClientState( GL_VERTEX_ARRAY );
  glEnableClientState( GL_COLOR_ARRAY );

  // indicar el formato y la direccion de memoria del array de vertices
  // (son tuplas de 3 valores float, sin espacio entre ellas)
  glVertexPointer( 3, GL_FLOAT, 0, v.data() );
  
  // indicamos el color con el que se van a pintar las caras (dependiendo de que modo se ha cogido)
  if(color_pintar == "puntos") glColorPointer(3, GL_FLOAT, 0, color_points);
  else if(color_pintar == "lineas") glColorPointer(3, GL_FLOAT, 0, color_lines);
  else if(color_pintar == "solido") glColorPointer(3, GL_FLOAT, 0, color_solid_inm);

  // visualizar, indicando: tipo de primitiva, numero de indices,
  // tipo de los indices, y direccion de la tabla de indices
  glDrawElements( GL_TRIANGLES, f.size()*3, GL_UNSIGNED_INT, f.data());

  // deshabilitar array de vertices y el color
  glDisableClientState( GL_VERTEX_ARRAY );
  glDisableClientState( GL_COLOR_ARRAY );
  
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

void Malla3D::draw_ModoDiferido(std::string color_pintar)
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....
   

   // creamos los identificadores del VBO para las caras y para los vertices
   if (id_vbo_ver == 0 && id_vbo_tri == 0)
   {
      id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER,3*sizeof(float) * v.size(), v.data());       // id para los vertices
      id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER,3*sizeof(int) * f.size(), f.data()); // id para las caras
   }

   // una vez creados, procedemos a visualizar la malla
   
   //especificar localización y formato de la tabla de vértices, habilitar tabla
   // activar VBO de vertices
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);

   // especifica formato y ofsset (=0)
   glVertexPointer(3, GL_FLOAT, 0, 0);

   // desactivar VBO de vertices
   glBindBuffer(GL_ARRAY_BUFFER, 0);

   // habilitar tabla de vertices y de colores
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);

   // indicamos el color con el que se van a pintar las caras (dependiendo de que modo se ha cogido)
   if(color_pintar == "puntos") glColorPointer(3, GL_FLOAT, 0, color_points);
   else if(color_pintar == "lineas") glColorPointer(3, GL_FLOAT, 0, color_lines);
   else if(color_pintar == "solido") glColorPointer(3, GL_FLOAT, 0, color_solid_dif);

   // visualizar triangulos con glDrawElements (puntero a tabla == 0)
   // activar VBO de triangulos
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_vbo_tri);

   // dibujamos los triangulos
   glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);

   // desactivar VBO de triangulos
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   // desactivar uso de array de vertices y color
   glDisableClientState(GL_VERTEX_ARRAY);
   glDisableClientState(GL_COLOR_ARRAY);

}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(int modo_dibujado, bool puntos, bool lineas,bool solido, bool ajedrez)
{
   // completar .....(práctica 1)
   glEnable(GL_CULL_FACE);
   color_pintar = "solido";

   // contemplar que aspectos se van a visualizar (puntos, lineas, solido, ajedrez)
   // solido y ajedrez serán independientes, mientras este ajedrez, no se podran ver los otros 3
   if (puntos){
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
      // hacemos que los puntos sean mas grandes y aumentamos su tamaño para que sean visibles
      glEnable(GL_PROGRAM_POINT_SIZE);
      glPointSize(3);
      color_pintar = "puntos";
      if(modo_dibujado == 1) this->draw_ModoInmediato(color_pintar);
      else if(modo_dibujado == 2) this->draw_ModoDiferido(color_pintar);
   }

   if (lineas){
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      color_pintar = "lineas";
      if(modo_dibujado == 1) this->draw_ModoInmediato(color_pintar);
      else if(modo_dibujado == 2) this->draw_ModoDiferido(color_pintar);
   }

   if (solido){
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      color_pintar = "solido";
      if(modo_dibujado == 1) this->draw_ModoInmediato(color_pintar);
      else if(modo_dibujado == 2) this->draw_ModoDiferido(color_pintar);
   }
   
   if(ajedrez) this->draw_ModoAjedrez();
}

// void Malla3D::inicializarColores(){
//    for(int i=0; i<v.size(); i++){
//       colores[i] = {1.0, 0.5, 0.0};
//    }
// }