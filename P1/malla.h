// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:
   // dibuja el objeto en modo ajedrez(inmediato)
   void draw_ModoAjedrezInmediato();

   // dibuja el objeto en modo ajedrez(diferido)
   void draw_ModoAjedrezDiferido();

   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato(std::string color_pintar);

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido(std::string color_pintar);

   // funcion para producir un identificador de VBO
   GLuint CrearVBO( GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram);

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(int modo_dibujado, bool puntos, bool lineas, bool solido, bool ajedrez);

   void inicializarColores();
protected:

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)
   std::string color_pintar = "";
   
   std::vector<Tupla3f> c_inm, c_dif, c_line, c_point; // tabla de colores de los vertices
   std::vector<Tupla3f> v;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f; // una terna de 3 enteros por cada cara o triángulo
   
   GLuint id_vbo_ver   = 0,
          id_vbo_tri   = 0,
          id_vbo_color_dif = 0,
          id_vbo_color_point = 0,
          id_vbo_color_line  = 0,
          id_vbo_color_chess_a = 0,
          id_vbo_color_chess_b = 0,
          id_vbo_tri_a = 0, id_vbo_tri_b = 0;

} ;


#endif
