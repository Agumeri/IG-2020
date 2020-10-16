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
   // dibuja el objeto en modo ajedre
   void draw_ModoAjedrez();

   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato(bool puntos, bool lineas,bool solido);

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido(bool puntos, bool lineas,bool solido);

   // funcion para producir un identificador de VBO
   GLuint CrearVBO( GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram);

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(int modo_dibujado, bool puntos, bool lineas, bool solido, bool ajedrez);

protected:

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)

   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   

   // completar: tabla de colores, tabla de normales de vértices
   private:
      GLuint id_vbo_ver = 0;
      GLuint id_vbo_tri = 0;

      // std::vector<Tupla3f> color_solid_inm, color_solid_dif, color_lines, color_points;

      // tablas de colores
         // solido inmediato
         GLfloat color_solid_inm[24] = {
            1.0, 0.5, 0.0,
            1.0, 0.5, 0.0,
            1.0, 0.5, 0.0,
            1.0, 0.5, 0.0,
            1.0, 0.5, 0.0,
            1.0, 0.5, 0.0,
            1.0, 0.5, 0.0,
            1.0, 0.5, 0.0,
         };

         // solido modo diferido 
         GLfloat color_solid_dif[24] = {
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
         };

         // lineas
         GLfloat color_lines[24] = {
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 0.0, 0.0,
         };

         // puntos
         GLfloat color_points[24] = {
            0.0, 1.0, 1.0,
            0.0, 1.0, 1.0,
            0.0, 1.0, 1.0,
            0.0, 1.0, 1.0,
            0.0, 1.0, 1.0,
            0.0, 1.0, 1.0,
            0.0, 1.0, 1.0,
            0.0, 1.0, 1.0,
         };

      //***************************************************
} ;


#endif
